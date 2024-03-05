#!/bin/bash

# Ensure the output directory exists
mkdir -p converted_images

# Loop through all PNG files in the current directory and convert to XPM
for file in *.png; do
    output_file="converted_images/$(basename "${file%.png}.xpm")"
    convert "$file" "$output_file"
done
