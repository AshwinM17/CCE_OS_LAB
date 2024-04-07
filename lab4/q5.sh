#!/bin/sh

num_patterns=$(( $# ))
patterns=("${@:1:num_patterns}")
input_file="${!num_patterns}"


while true;do
    echo "a. Search the patterns in the given input file."
    echo "b. Delete all occurrences of the pattern in the given input file."
    echo "c. Exit"

    read choice

    case "$choice" in
        a)
            echo "Searching patterns in $input_file:"
            for pattern in "${patterns[@]}"; do
                grep "$pattern" "$input_file"
            done
            ;;
        b)
            echo "Deleting occurrences of patterns in $input_file:"
            for pattern in "${patterns[@]}"; do
                sed -i "s/$pattern//g" "$input_file"
            done
            echo "Occurrences deleted."
            ;;
        c)
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid choice. Please enter 'a', 'b', or 'c'."
            ;;
    esac

done
