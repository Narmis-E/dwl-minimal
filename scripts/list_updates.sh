#!/bin/bash

# Check for updates and count them
updates=$(checkupdates 2>/dev/null)
update_count=$(echo "$updates" | wc -l)

# Create a JSON output for Waybar
if [[ $update_count -gt 0 ]]; then
    # Format the tooltip with the list of packages
    tooltip=$(echo "$updates" | awk '{print $1}' | paste -sd ', ' -)
    echo "{\"text\": \"$update_count\", \"tooltip\": \"$tooltip\"}"
else
    echo "{\"text\": \"0\", \"tooltip\": \"No updates available\"}"
fi

