#include <stdlib.h>

void setenviron()
{
   setenv("BASH","/bin/bash",1);
   setenv("BASHOPTS","checkwinsize:cmdhist:expand_aliases:extglob:extquote:force_fignore:histappend:interactive_comments:progcomp:promptvars:sourcepath",1);
   setenv("BASH_COMPLETION","/etc/bash_completion",1);
   setenv("BASH_COMPLETION_COMPAT_DIR","/etc/bash_completion.d",1);
   setenv("BASH_COMPLETION_DIR","/etc/bash_completion.d",1);
   setenv("BASH_LINENO","()",1);
   setenv("BASH_SOURCE","()",1);
   setenv("BASH_VERSINFO","([0]=\"4\" [1]=\"2\" [2]=\"24\" [3]=\"1\" [4]=\"release\" [5]=\"i686-pc-linux-gnu\")",1);
   setenv("BASH_VERSION","'4.2.24(1)-release'",1);
   setenv("COLORTERM","gnome-terminal",1);
   setenv("COLUMNS","144",1);
   setenv("DBUS_SESSION_BUS_ADDRESS","unix:abstract=/tmp/dbus-IZsRj9mUK7,guid=5501bcb4ecf59bfbcd0cc8380000001d",1);
   setenv("DEFAULTS_PATH","/usr/share/gconf/ubuntu-2d.default.path",1);
   setenv("DESKTOP_SESSION","ubuntu-2d",1);
   setenv("DIRSTACK","()",1);
   setenv("DISPLAY",":0",1);
   setenv("EUID","1000",1);
   setenv("GDMSESSION","ubuntu-2d",1);
   setenv("GNOME_DESKTOP_SESSION_ID","this-is-deprecated",1);
   setenv("GNOME_KEYRING_CONTROL","/tmp/keyring-bzPfHx",1);
   setenv("GNOME_KEYRING_PID","3982",1);
   setenv("GPG_AGENT_INFO","/tmp/keyring-bzPfHx/gpg:0:1",1);
   setenv("GROUPS","()",1);
   setenv("GTK_MODULES","canberra-gtk-module:canberra-gtk-module",1);
   setenv("HISTCONTROL","ignoredups:ignorespace",1);
   setenv("HISTFILE","/home/asaini/.bash_history",1);
   setenv("HISTFILESIZE","2000",1);
   setenv("HISTSIZE","1000",1);
   setenv("HOME","/home/asaini",1);
   setenv("HOSTNAME","asaini-VirtualBox",1);
   setenv("HOSTTYPE","i686",1);
   setenv("IFS","$' \t\n'",1);
   setenv("LANG","en_US.UTF-8",1);
   setenv("LD_LIBRARY_PATH","/usr/local/lib:",1);
   setenv("LESSCLOSE","'/usr/bin/lesspipe %s %s'",1);
   setenv("LESSOPEN","'| /usr/bin/lesspipe %s'",1);
   setenv("LINES","41",1);
   setenv("LOGNAME","asaini",1);
   setenv("LS_COLORS","'rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arj=01;31:*.taz=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lz=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.axv=01;35:*.anx=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.axa=00;36:*.oga=00;36:*.spx=00;36:*.xspf=00;36:'",1);
   setenv("MACHTYPE","i686-pc-linux-gnu",1);
   setenv("MAILCHECK","60",1);
   setenv("MANDATORY_PATH","/usr/share/gconf/ubuntu-2d.mandatory.path",1);
   setenv("OLDPWD","/home/asaini",1);
   setenv("OPTERR","1",1);
   setenv("OPTIND","1",1);
   setenv("OSTYPE","linux-gnu",1);
   setenv("PATH","/usr/lib/lightdm/lightdm:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games",1);
   setenv("PIPESTATUS","([0]=\"0\")",1);
   setenv("PPID","27666",1);
   //setenv("PS1","'\[\e]0;\u@\h: \w\a\]${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '",1);
   setenv("PS2","'> '",1);
   setenv("PS4","'+ '",1);
   setenv("PWD","/home/asaini/TheDream",1);
   setenv("SESSION_MANAGER","local/asaini-VirtualBox:@/tmp/.ICE-unix/3993,unix/asaini-VirtualBox:/tmp/.ICE-unix/3993",1);
   setenv("SHELL","/bin/bash",1);
   setenv("SHELLOPTS","braceexpand:emacs:hashall:histexpand:history:interactive-comments:monitor",1);
   setenv("SHLVL","1",1);
   setenv("SSH_AGENT_PID","4062",1);
   setenv("SSH_AUTH_SOCK","/tmp/keyring-bzPfHx/ssh",1);
   setenv("TERM","xterm",1);
   setenv("UBUNTU_MENUPROXY","libappmenu.so",1);
   setenv("UID","1000",1);
   setenv("USER","asaini",1);
   setenv("WINDOWID","90476718",1);
   setenv("XAUTHORITY","/home/asaini/.Xauthority",1);
   setenv("XDG_CONFIG_DIRS","/etc/xdg/xdg-ubuntu-2d:/etc/xdg",1);
   setenv("XDG_CURRENT_DESKTOP","Unity",1);
   setenv("XDG_DATA_DIRS","/usr/share/ubuntu-2d:/usr/share/gnome:/usr/local/share/:/usr/share/",1);
   setenv("XDG_SEAT_PATH","/org/freedesktop/DisplayManager/Seat0",1);
   setenv("XDG_SESSION_COOKIE","c09943c5a85cb4da99948058000007b4-1363922999.352013-39577668",1);
   setenv("XDG_SESSION_PATH","/org/freedesktop/DisplayManager/Session0",1);
   setenv("_","my_shell.c",1);
   setenv("__grub_script_check_program","grub-script-check",1);
}
