TERM=xterm; export TERM

alias ggcc="gcc -O3 -g -std=c99 -Wall -Wextra -Werror"
alias rec="avconv -f x11grab -r 25 -s 1920x1080 -i :0.0 -c:v libx264 ~/rec.mp4"
alias sicp="rlwrap -r -c -f "$HOME"/.config_repo/scheme_completion mit-scheme"
alias ls='ls -F'

PATH=$PATH:.

nt()
{
	"$@" &
	disown
	exit
}

cl() { cd "$@" && ls; }
PS1='\[\033[38;5;124m\]\w\$\[\033[00m\] '
