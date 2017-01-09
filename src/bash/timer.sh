#!/bin/bash

countdown () 
{ 
        if (($# != 1)) || [[ $1 = *[![:digit:]]* ]]; then
                echo "Usage: countdown seconds";
                return;
        fi;

        local t=$1*60 remaining=$1*60;
        SECONDS=0;

        while sleep 60s; do

                if (( (remaining=t-SECONDS) <= 0 )); then
                        nohup aplay -vv /usr/share/sounds/alsa/Rear_Center.wav;
                        break;
                fi;

        done
}&> /dev/null

while :; do
        countdown $1;
done
