#define COLOR(hex)    { ((hex >> 24) & 0xFF) / 255.0f, \
                        ((hex >> 16) & 0xFF) / 255.0f, \
                        ((hex >> 8) & 0xFF) / 255.0f, \
                        (hex & 0xFF) / 255.0f }
static const int sloppyfocus               = 1;
static const int bypass_surface_visibility = 0;
static const int smartgaps                 = 1;  /* 1 means no outer gap when there is only one window */
static int gaps                            = 1;  /* 1 means gaps between windows are added */
static const unsigned int gappx            = 7; /* gap pixel between windows */
static const unsigned int borderpx         = 3;
static const float rootcolor[]             = COLOR(0x222222ff);
static const float bordercolor[]           = COLOR(0x3F3F3Fff);
static const float focuscolor[]            = COLOR(0x7F7F7Fff);
static const float urgentcolor[]           = COLOR(0xff0000ff);
static const char *cursor_theme            = "Breeze_Snow";
static const char cursor_size[]            = "24"; /* Make sure it's a valid integer, otherwise things will break */
static const float fullscreen_bg[]         = {0.1f, 0.1f, 0.1f, 1.0f};
#define TAGCOUNT (9)
static int log_level = WLR_ERROR;

/* Autostart */
static const char *const autostart[] = {
        "wbg", "/home/narmis/Pictures/torvalds.png", NULL,
	"waybar", NULL,
	"swaync", NULL,
	"/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1", NULL,
        NULL /* terminate */
};

static const Rule rules[] = {
	{ "Gimp_EXAMPLE",     NULL,       0,            1,           -1 },
	{ "firefox_EXAMPLE",  NULL,       1 << 8,       0,           -1 },
};

static const Layout layouts[] = {
	{ "[]=",      tile },
	{ "><>",      NULL },
	{ "[M]",      monocle },
	{ "@|@",      snail },
};

static const MonitorRule monrules[] = {
	{ "eDP-2",       0.55f, 1,      1.5,    &layouts[3], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
	{ "DP-2",       0.55f, 1,      1,    &layouts[3], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
	{ "HDMI-A-1",       0.55f, 1,      1,    &layouts[3], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 }
};

static const struct xkb_rule_names xkb_rules = {
	.options = NULL,
};

static const int repeat_rate = 25;
static const int repeat_delay = 600;

static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const int drag_lock = 1;
static const int natural_scrolling = 0;
static const int disable_while_typing = 1;
static const int left_handed = 0;
static const int middle_button_emulation = 0;
static const enum libinput_config_scroll_method scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;
static const enum libinput_config_click_method click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;
static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;
static const enum libinput_config_accel_profile accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
static const double accel_speed = 0.0;
static const enum libinput_config_tap_button_map button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;

#define MODKEY WLR_MODIFIER_LOGO

#define TAGKEYS(KEY,SKEY,TAG) \
	{ MODKEY,                    KEY,            view,            {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL,  KEY,            toggleview,      {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_SHIFT, SKEY,           tag,             {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL|WLR_MODIFIER_SHIFT,SKEY,toggletag, {.ui = 1 << TAG} }

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const char *termcmd[] = { "kitty", NULL };
static const char *menucmd[] = { "fuzzel", NULL };
static const char *powermenucmd[] = { "/home/narmis/.local/bin/powermenu.sh", NULL };
static const char *hzcmd[] = { "/home/narmis/.local/bin/hz.sh", NULL };
static const char *kbdcmd[] = { "/home/narmis/.local/bin/kbd-backlight.sh", NULL };
static const char *browcmd[] = { "firefox", NULL };
static const char *pickercmd[] = { "hyprpicker", "-a" };
static const char *scrotcmd[] = { "/home/narmis/.local/bin/screenshot.sh", "--area" };

static const char *notifcmd[]  =   { "swaync-client", "-t", "-sw" };

static const char *brightness_up[]  =   { "brightnessctl", "set", "5%+" };
static const char *brightness_down[]  = { "brightnessctl", "set", "5%-" };

static const char *volume_up[]  =   { "amixer", "-q", "sset", "Master", "5%+" };
static const char *volume_down[]  = { "amixer", "-q", "sset", "Master", "5%-" };
static const char *volume_mute[]  = { "amixer", "-q", "sset", "Master", "toggle" };

static const Key keys[] = {
	{ MODKEY,                    XKB_KEY_space,      spawn,          {.v = menucmd} },
	{ MODKEY,                    XKB_KEY_z,	         spawn,          {.v = kbdcmd} },
	{ MODKEY,                    XKB_KEY_r,      	 spawn,          {.v = hzcmd} },
	{ MODKEY,                    XKB_KEY_x,      	 spawn,          {.v = powermenucmd} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_N, 	 spawn,          {.v = notifcmd} },
	{ MODKEY,		     XKB_KEY_Print,	 spawn,		 {.v = scrotcmd} },
	{ MODKEY,		     XKB_KEY_Return,     spawn,          {.v = termcmd} },
	{ MODKEY,		     XKB_KEY_w,		 spawn,		 {.v = browcmd} },
	{ MODKEY,		     XKB_KEY_p,		 spawn,		 {.v = pickercmd} },
	{ 0,              XKB_KEY_XF86MonBrightnessUp,   spawn, 	 {.v = brightness_up } },
	{ 0,    	  XKB_KEY_XF86MonBrightnessDown, spawn, 	 {.v = brightness_down } },
	{ 0,              XKB_KEY_XF86AudioLowerVolume,  spawn, 	 {.v = volume_down } },
	{ 0,    	  XKB_KEY_XF86AudioRaiseVolume,  spawn, 	 {.v = volume_up } },
	{ 0,              XKB_KEY_XF86AudioMute,	 spawn, 	 {.v = volume_mute } },
	{ MODKEY,                    XKB_KEY_j,          focusstack,     {.i = +1} },
	{ MODKEY,                    XKB_KEY_k,          focusstack,     {.i = -1} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_J,          movestack,      {.i = +1} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_K,          movestack,      {.i = -1} },
	{ MODKEY,                    XKB_KEY_i,          incnmaster,     {.i = +1} },
	{ MODKEY,                    XKB_KEY_d,          incnmaster,     {.i = -1} },
	{ MODKEY,                    XKB_KEY_h,          setmfact,       {.f = -0.05f} },
	{ MODKEY,                    XKB_KEY_l,          setmfact,       {.f = +0.05f} },
	{ MODKEY,                    XKB_KEY_Tab,        view,           {0} },
	{ MODKEY,                    XKB_KEY_g,          togglegaps,     {0} },
	{ MODKEY,                    XKB_KEY_n,	         zoom,           {0} },
/*	{ MODKEY,                    XKB_KEY_f,          setlayout,      {.v = &layouts[1]} },*/
/*	{ MODKEY,                    XKB_KEY_m,          setlayout,      {.v = &layouts[2]} },*/
/*	{ MODKEY,                    XKB_KEY_space,      setlayout,      {0} },*/
	{ MODKEY,		     XKB_KEY_q,          killclient,     {0} },
	{ MODKEY,                    XKB_KEY_t,          setlayout,      {.v = &layouts[0]} },
	{ MODKEY,		     XKB_KEY_s,	         togglefloating, {0} },
	{ MODKEY,                    XKB_KEY_f,          togglefullscreen, {0} },
	{ MODKEY,                    XKB_KEY_0,          view,           {.ui = ~0} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_parenright, tag,            {.ui = ~0} },
	{ MODKEY,                    XKB_KEY_comma,      focusmon,       {.i = WLR_DIRECTION_LEFT} },
	{ MODKEY,                    XKB_KEY_period,     focusmon,       {.i = WLR_DIRECTION_RIGHT} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_less,       tagmon,         {.i = WLR_DIRECTION_LEFT} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_greater,    tagmon,         {.i = WLR_DIRECTION_RIGHT} },
	TAGKEYS(          XKB_KEY_1, XKB_KEY_exclam,                     0),
	TAGKEYS(          XKB_KEY_2, XKB_KEY_at,                         1),
	TAGKEYS(          XKB_KEY_3, XKB_KEY_numbersign,                 2),
	TAGKEYS(          XKB_KEY_4, XKB_KEY_dollar,                     3),
	TAGKEYS(          XKB_KEY_5, XKB_KEY_percent,                    4),
	TAGKEYS(          XKB_KEY_6, XKB_KEY_asciicircum,                5),
	TAGKEYS(          XKB_KEY_7, XKB_KEY_ampersand,                  6),
	TAGKEYS(          XKB_KEY_8, XKB_KEY_asterisk,                   7),
	TAGKEYS(          XKB_KEY_9, XKB_KEY_parenleft,                  8),
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Q,          quit,           {0} },
	{ WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_Terminate_Server, quit, {0} },
#define CHVT(n) { WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_XF86Switch_VT_##n, chvt, {.ui = (n)} }
	CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
	CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),
};

static const Button buttons[] = {
	{ MODKEY, BTN_LEFT,   moveresize,     {.ui = CurMove} },
	{ MODKEY, BTN_MIDDLE, togglefloating, {0} },
	{ MODKEY, BTN_RIGHT,  moveresize,     {.ui = CurResize} },
};

