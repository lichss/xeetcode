#!/bin/bash

# Find all executable files named "main"
files=$(find . -type f -name "main" -executable 2>/dev/null)

# Exit if none found
if [ -z "$files" ]; then
    echo "No executable 'main' files found."
    exit 0
fi

echo "Found the following executable files:"
echo "$files"
echo

# Prompt for confirmation
read -p "Delete these files? (y/N): " -n 1 -r
echo

if [[ $REPLY =~ ^[Yy]$ ]]; then
    find . -type f -name "main" -executable -delete
    echo "Cleanup completed."
else
    echo "Deletion cancelled."
fi