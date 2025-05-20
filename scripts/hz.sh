#!/bin/sh

# kbd backlight script using tofi

CHOSEN=$(printf "󱧑  60hz\n󰷜  120hz" | tofi --config "$HOME"/.config/tofi/hz-config)

case "$CHOSEN" in
	"󱧑  60hz") wlr-randr --output eDP-2 --mode 2880x1800@60.001Hz ;;
	"󰷜  120hz") wlr-randr --output eDP-2 --mode 2880x1800@120.001Hz ;;
	*) exit 1 ;;
esac

