#!/bin/bash

# A little Bash script to make a mirror of your Github repositories and keep
# them up-to-date.
# Why mirroring? Because I can!
# Also, it will be very useful if one day a meteorite crashes into Github
# servers (even if it will not happen).

# https://gist.github.com/950441

# FIXME:
#   - handle when several pages (see WARNING)
#   - check 'X-RateLimit-Remaining' HTTP header
# see http://develop.github.com/p/repo.html

USERNAME=infertux
ROOT=/srv/git

[ "$1" = "-v" ] && VERBOSE='-v' || VERBOSE=''

[ -d "$ROOT" ] || { echo "$ROOT is not a directory!"; exit 1; }
cd "$ROOT"

output=$(curl -si https://api.github.com/users/$USERNAME/repos)

if [ $(echo "$output" | grep -c 'X-Last:') -ne 0 ] ; then
    echo "WARNING: Only the first page will be fetched!" >&2
fi

repos=$(echo "$output" | grep -Eo '"(clone_url|description)": "(.*)"' | \
    awk -F'"' '{printf $2" "$4"\n"}')

IFS=$'\n'
for repo in $repos; do
    key=$(echo "$repo" | cut -d' ' -f1)
    value=$(echo "$repo" | cut -d' ' -f2-)
    case $key in
        clone_url)
            url=$value
            dir=$(echo "$value" | awk -F/ '{print $NF}')
        ;;
        description)
            desc=$value
        ;;
        *)
            echo "Unknown key: $key" >&2
            exit 1
        ;;
    esac

    ((counter++))
    if [ $counter -eq 2 ]; then
        counter=0
        [ $VERBOSE ] && echo -e "Dir: '$dir'\nDesc: '$desc'"
        if [ -d "$dir" ] ; then
            cd "$dir"
            git fetch $VERBOSE
            cd "$ROOT"
        else
            [ $VERBOSE ] && echo "Clone $url"
            git clone $VERBOSE --mirror "$url"
        fi

        filename="$dir/description"
        [ -f "$filename" ] || { echo "No description file for '$dir'!"; exit 1; }
        echo "$desc" > "$filename"
        [ $VERBOSE ] && cat "$filename"

        dir=
        desc=
    fi
done

[ $VERBOSE ] && echo "Done."

exit 0
