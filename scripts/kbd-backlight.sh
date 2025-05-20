#!/bin/sh

# kbd backlight script using tofi

CHOSEN=$(printf "󰌐 off\n󰌏 low\n full" | tofi --config "$HOME"/.config/tofi/kbd-config)

case "$CHOSEN" in
	"󰌐 off") brightnessctl -d platform::kbd_backlight s 0 ;;
	"󰌏 low") brightnessctl -d platform::kbd_backlight s 50% ;;
	" full") brightnessctl -d platform::kbd_backlight s 100% ;;
	*) exit 1 ;;
esac

