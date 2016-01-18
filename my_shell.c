#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_shell.h"

struct commmand_struct
{
   char *cmd_name;
   char **argv;
   int argc;
};

void initialize(struct commmand_struct *cmd)
{
    cmd->argc = 0;
    cmd->argv = NULL;
    cmd->cmd_name = NULL;
}

int findargc(char *line)
{
   int i=0;
   int FLAG = 0;
   int count = 0;

   while( line[i] != '\0' )
   {
       if ( line[i] != ' ' && line[i] != '\n' )
          break;
       i++;
   }
   
   while( line[i] != '\0' )
   {
      if ( line[i] == '<' || line[i] == '>' || line[i] == '&' || line[i] == '|' )
         break;

      if ( line[i] == '"' && FLAG != 2 )
      {
          FLAG = 2;
      }
      else if ( line[i] == '"' && FLAG == 2 )
      {
          FLAG = 1;
          count++;
      }
      else if ( (line[i] == ' ' || line[i] == '\n') && FLAG == 0 )
      {
         count++;
         FLAG = 1;
      }
      else if ( (line[i] != ' ' && line[i] != '\n') && FLAG == 1 )
           FLAG = 0;

      i++;
   }
 
   return count;
}

void buildcommand(struct commmand_struct *cmd, char *line)
{
   char buffer[50];

   int i,j,k,FLAG;

   if ( cmd->argc == 0 )
     return;

   cmd->argv = (char **)malloc(sizeof(char *) * (cmd->argc + 1));

   i = 0;
   while( line[i] != '\0' )
   {
      if ( line[i] != ' ' )
        break;
      i++;
   }

   j = 0;
   while( line[i] != ' ' && line[i] != '\n' )
   { 
      buffer[j] = line[i];
      j++;
      i++;
   }
   buffer[j] = '\0';

   cmd->cmd_name = strdup(buffer);
   cmd->argv[0] = strdup(buffer);

   if ( cmd->argc == 1 )
   {
     cmd->argv[1] = NULL;
     return;
   }

   while( line[i] != '\0' )
   {
       if ( line[i] != ' ' )
          break;
       i++;
   }

   j = 0;
   k = 1;
   FLAG = 0;
   while( line[i] != '\0' )
   {
      if ( line[i] == '<' || line[i] == '>' || line[i] == '&' || line[i] == '|' )
         break;

      if ( (line[i] != ' ' && line[i] != '\n') || FLAG == 2 )
      {
         buffer[j] = line[i];
         j++;
      }

      if ( line[i] == '"' && FLAG != 2 )
      {
          FLAG = 2;
      }
      else if ( line[i] == '"' && FLAG == 2 )
      {
          FLAG = 1;
          buffer[j] = '\0';
          cmd->argv[k] = strdup(buffer);
          j = 0;
          k++;
      }
      else if ( (line[i] == ' ' || line[i] == '\n') && FLAG == 0 )
      {
         buffer[j] = '\0';
         cmd->argv[k] = strdup(buffer); 
         j = 0;
         k++;
         FLAG = 1;
      }
      else if ( (line[i] != ' ' && line[i] != '\n') && FLAG == 1 )
           FLAG = 0;

      i++;
   }
   cmd->argv[k] = NULL;
}

char * checkcmd(struct commmand_struct *cmd)
{
   int FLAG = 0;
   int length;

   char find_path[50];

   if ( strchr(cmd->cmd_name,'/') )
   {
      strcpy(find_path,cmd->cmd_name);

      if ( access(find_path,F_OK) != -1 )
          FLAG = 1;
   }
   else
   {
      char *path = strdup(getenv("PATH"));
      char *name = strtok(path,":");

      length = strlen(name);
      strcpy(find_path,name);
      find_path[length] = '/';
      find_path[length+1] = '\0';
      strcat(find_path,cmd->cmd_name);

      if ( access(find_path,F_OK) != -1 )
         FLAG = 1;

      if ( FLAG == 0 )
      {
         while( (name = strtok(NULL,":")) != NULL )
         {
            length = strlen(name);
            strcpy(find_path,name);
            find_path[length] = '/';
            find_path[length+1] = '\0';

            strcat(find_path,cmd->cmd_name);
            if ( access(find_path,F_OK) != -1 )
            {

               FLAG = 1;
               break;
            }
         }
      }
      free(path);
   }

   if ( FLAG == 1 )
      return strdup(find_path);
   else
      return NULL;
}

int main(int argc, char *argv[])
{
  char line[100];
  char regex[20] = "\n|[ 	]*";

  //Environment variables
  setenviron();
 
  while(1)
  {  
     struct commmand_struct cmd1, cmd2;
     initialize(&cmd1);
     initialize(&cmd2);

     int BACKGROUND, OUTPUT, INPUT, PIPE;
     int pipeID[2];
     int fd;
     char *rwfile;
     char *find_path1, *find_path2;

     // initialize variables 
     BACKGROUND = OUTPUT = INPUT = PIPE = 0;
  
     printf("%s:",getenv("PWD"));

     if ( fgets(line,sizeof(line),stdin) == NULL )
     {
        printf("\n");
        exit(1);
     }

     cmd1.argc = findargc(line);
     buildcommand(&cmd1,line);

     if ( cmd1.cmd_name == NULL )
        continue;

     find_path1 = checkcmd(&cmd1);
  
     if ( find_path1 == NULL )
     {
        printf("cmd '%s' not found\n",cmd1.argv[0]);
        continue;
     } 

     char *temp;

     temp = strchr(line,'|');
     if ( temp != NULL )
     {
        PIPE = 1;
        pipe(pipeID);
        cmd2.argc = findargc(&temp[1]);
        buildcommand(&cmd2,&temp[1]);
 
        find_path2 = checkcmd(&cmd2);
        if ( find_path2 == NULL )
        {
           printf("cmd '%s' nod found\n",cmd2.argv[0]);
           continue;
        }
     }

     if ( temp == NULL )
     {
        temp = strchr(line,'<');
        if ( temp != NULL )
        {
           INPUT = 1;
           rwfile = strtok(strdup(&temp[1]),regex);
        }
     }

     if ( temp == NULL )
     {
        temp = strchr(line,'>');
        if ( temp != NULL )
        {
           OUTPUT = 1;
           rwfile = strtok(strdup(&temp[1]),regex);
        }
     }

     if ( temp == NULL )
     {
        temp = strchr(line,'&');
        if ( temp != NULL )
           BACKGROUND = 1;
     }

     if ( fork() == 0 )
     {
         if ( OUTPUT == 1 )
	 {
	   fd = open(rwfile,O_WRONLY|O_CREAT);
           close(1);
           dup(fd);
           close(fd);
         }
         else if ( INPUT == 1 )
         {
            if ( access(rwfile,F_OK) != -1 )
	    {
               fd = open(rwfile,O_RDONLY);
               close(0);
               dup(fd);
               close(fd);
	    }
            else
	       printf("%s doesnot exist, (ignoring file) using stdin instead\n",rwfile);
         }
         else if ( PIPE == 1 )
         {
            close(1);
            dup(pipeID[1]);
            close(pipeID[1]);
         }

         execv(find_path1,cmd1.argv);
     }
     if ( PIPE == 1 )
     {
        if ( fork() == 0 )
        {
           close(0);
           dup(pipeID[0]);
           close(pipeID[0]);

           execv(find_path2,cmd2.argv);
        }
     }

     if ( PIPE == 1 )
     {
        wait();     
     } 
     else
     {
       if ( BACKGROUND == 0 )
         wait();
     } 
  }

  return 0;
}
