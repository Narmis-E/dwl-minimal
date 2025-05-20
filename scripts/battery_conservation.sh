#!/bin/sh

# Enables or disables battery conservation (set to 80%). note: chown conservation_mode

CHOSEN=$(printf "󱈑 Enable Battery Conservation\n󱟠 Disable Battery Conservation" | tofi --config "$HOME"/.config/tofi/hz-config)

case "$CHOSEN" in
	"󱈑 Enable Battery Conservation") echo 1 > /sys/bus/platform/drivers/ideapad_acpi/VPC2004:00/conservation_mode ;;
	"󱟠 Disable Battery Conservation") echo 0 > /sys/bus/platform/drivers/ideapad_acpi/VPC2004:00/conservation_mode ;;
	*) exit 1 ;;
esac

