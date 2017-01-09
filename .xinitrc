eval 'dbus-launch --auto-syntax'
xsetroot -cursor_name left_ptr &
xrdb ~/.Xresources
xmodmap .Xmodmap
xsetroot -solid "#ffffd7"
xset fp+ /home/steve/.fonts
xset fp rehash
redshift -l 40.4867:-74.4444 &
xbindkeys
exec openbsd-cwm
