#!/bin/sh

option="$1"
file="$2"

case "$option" in  
	-linecount)
        result=$(wc -l < "$file")
        echo "Line count in $file: $result"
        ;;
    -wordcount)
        result=$(wc -w < "$file")
        echo "Word count in $file: $result"
        ;;
    -charcount)
        result=$(wc -c < "$file")
        echo "Character count in $file: $result"
        ;;
    *)
        echo "Invalid option. Please use -linecount, -wordcount, or -charcount."
        exit 1
        ;;
esac
