/* See LICENSE file for copyright and license details. */
/* Copyright (C) 2020-2024 Aditya Shakya <adi1090x@gmail.com>
 * 
 * 2BWM Configuration for Archcraft
 * 
 * */

/* ******************** Configurations ******************** */

//---Modifiers---//
/* Super,Windows,Logo key or check xmodmap(1) with -pm defined in /usr/include/xcb/xproto.h */
#define MODKEY XCB_MOD_MASK_4
#define ALTKEY XCB_MOD_MASK_1

//---Speed---//
/* Move this many pixels when moving or resizing with keyboard unless the window has hints saying otherwise.
 *0)move step slow   1)move step fast
 *2)mouse slow       3)mouse fast     */
static const uint16_t movements[] = {20,40,15,400};

/* resize by line like in mcwm -- jmbi */
static const bool resize_by_line = true;

/* the ratio used when resizing and keeping the aspect */
static const float resize_keep_aspect_ratio = 1.03;

//---Offsets---//
/*0)offsetx          1)offsety
 *2)maxwidth         3)maxheight */
static const uint8_t offsets[] = {0,0,0,0};

//---Colors---//
/*0)focuscol         1)unfocuscol
 *2)fixedcol         3)unkilcol
 *4)fixedunkilcol    5)outerbordercol
 *6)emptycol         */
static const char *colors[] = {"#d8d8d8","#6f8a91","#a3be8c","#bf616a","#ebcb8b","#2e3440","#2e3440"};

/* if this is set to true the inner border and outer borders colors will be swapped */
static const bool inverted_colors = false;

//---Cursor---//
/* default position of the cursor:
 * correct values are:
 * TOP_LEFT, TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT, MIDDLE
 * All these are relative to the current window. */
#define CURSOR_POSITION MIDDLE

//---Borders---//
/*0) Outer border size. If you put this negative it will be a square.
 *1) Full borderwidth    2) Magnet border size
 *3) Resize border size  */
static const uint8_t borders[] = {5,7,2,3};

/* Windows that won't have a border.
 * It uses substring comparison with what is found in the WM_NAME
 * attribute of the window. You can test this using `xprop WM_NAME`
 */
#define LOOK_INTO "WM_NAME"
static const char *ignore_names[] = {"polybar", "bar", "xclock"};

//---Custom foo---//
static void halfandcentered(const Arg *arg)
{
	Arg arg2 = {.i=TWOBWM_MAXHALF_VERTICAL_LEFT};
	maxhalf(&arg2);
	Arg arg3 = {.i=TWOBWM_TELEPORT_CENTER};
	teleport(&arg3);
}

//---Sloppy focus behavior---//
/*
 * Command to execute when switching from sloppy focus to click to focus
 * The strings "Sloppy" and "Click" will be passed as the last argument
 * If NULL this is ignored
 */
static const char *sloppy_switch_cmd[] = {};

//static const char *sloppy_switch_cmd[] = { "notify-send", "toggle sloppy", NULL };
static void toggle_sloppy(const Arg *arg)
{
	is_sloppy = !is_sloppy;
	if (arg->com != NULL && LENGTH(arg->com) > 0) {
		start(arg);
	}
}

/* ******************** Commands ******************** */

/* Launch Apps */
static const char *termcmd[]  			= { "/usr/share/archcraft/2bwm/scripts/2bwm_term", NULL };
static const char *floatterm[]  		= { "/usr/share/archcraft/2bwm/scripts/2bwm_term", "--float", NULL };
static const char *fullterm[]  			= { "/usr/share/archcraft/2bwm/scripts/2bwm_term", "--full", NULL };
static const char *fmcmd[]    			= { "/usr/share/archcraft/2bwm/scripts/2bwm_apps", "--file", NULL };
static const char *editcmd[]  			= { "/usr/share/archcraft/2bwm/scripts/2bwm_apps", "--editor", NULL };
static const char *webcmd[]  			= { "/usr/share/archcraft/2bwm/scripts/2bwm_apps", "--web", NULL };

/* Rofi Menus */
static const char *rofi_cmd[] 			= { "/usr/share/archcraft/2bwm/scripts/rofi_launcher", NULL };
static const char *rofi_rootcmd[] 		= { "/usr/share/archcraft/2bwm/scripts/rofi_asroot", NULL };
static const char *rofi_mpdcmd[] 		= { "/usr/share/archcraft/2bwm/scripts/rofi_music", NULL };
static const char *rofi_nmcmd[]    		= { "/usr/share/archcraft/2bwm/scripts/network_menu", NULL };
static const char *rofi_powercmd[]  	= { "/usr/share/archcraft/2bwm/scripts/rofi_powermenu", NULL };
static const char *rofi_shotcmd[]  		= { "/usr/share/archcraft/2bwm/scripts/rofi_screenshot", NULL };
static const char *rofi_bluecmd[]  		= { "/usr/share/archcraft/2bwm/scripts/rofi_bluetooth", NULL };
static const char *rofi_runcmd[]  		= { "/usr/share/archcraft/2bwm/scripts/rofi_runner", NULL };

/* Misc */
static const char *cpickcmd[]  			= { "/usr/share/archcraft/2bwm/scripts/2bwm_colorpicker", NULL };
static const char *musicmd[]  			= { "/usr/share/archcraft/2bwm/scripts/2bwm_music", NULL };
static const char *lockcmd[]  			= { "betterlockscreen", "--lock", NULL };

/* Hardware keys for volume and brightness */
#include <X11/XF86keysym.h>
static const char *mutevol[] 			= { "/usr/share/archcraft/2bwm/scripts/2bwm_volume", "--toggle",  NULL };
static const char *mutemic[] 			= { "/usr/share/archcraft/2bwm/scripts/2bwm_volume", "--toggle-mic",  NULL };
static const char *upvol[]   			= { "/usr/share/archcraft/2bwm/scripts/2bwm_volume", "--inc",  	NULL };
static const char *downvol[] 			= { "/usr/share/archcraft/2bwm/scripts/2bwm_volume", "--dec",    	NULL };
static const char *upbl[] 				= { "/usr/share/archcraft/2bwm/scripts/2bwm_brightness", "--inc",    NULL };
static const char *downbl[] 			= { "/usr/share/archcraft/2bwm/scripts/2bwm_brightness", "--dec",  NULL };

/* Screenshot */
static const char *shotnow[]  			= { "/usr/share/archcraft/2bwm/scripts/2bwm_screenshot", "--now", NULL };
static const char *shotin5[]  			= { "/usr/share/archcraft/2bwm/scripts/2bwm_screenshot", "--in5", NULL };
static const char *shotin10[]  			= { "/usr/share/archcraft/2bwm/scripts/2bwm_screenshot", "--in10", NULL };
static const char *shotwin[]  			= { "/usr/share/archcraft/2bwm/scripts/2bwm_screenshot", "--win", NULL };
static const char *shotarea[]  			= { "/usr/share/archcraft/2bwm/scripts/2bwm_screenshot", "--area", NULL };

/* ******************** Keybindings ******************** */
/* Check /usr/include/X11/keysymdef.h for the list of all keys
 * 0x000000 is for no modkey
 * If you are having trouble finding the right keycode use the `xev` to get it
 * For example:
 * KeyRelease event, serial 40, synthetic NO, window 0x1e00001,
 *  root 0x98, subw 0x0, time 211120530, (128,73), root:(855,214),
 *  state 0x10, keycode 171 (keysym 0x1008ff17, XF86AudioNext), same_screen YES,
 *  XLookupString gives 0 bytes: 
 *  XFilterEvent returns: False
 *
 *  The keycode here is keysym 0x1008ff17, so use  0x1008ff17
 *
 * For AZERTY keyboards XK_1...0 should be replaced by :
 *      DESKTOPCHANGE(     XK_ampersand,                     0)
 *      DESKTOPCHANGE(     XK_eacute,                        1)
 *      DESKTOPCHANGE(     XK_quotedbl,                      2)
 *      DESKTOPCHANGE(     XK_apostrophe,                    3)
 *      DESKTOPCHANGE(     XK_parenleft,                     4)
 *      DESKTOPCHANGE(     XK_minus,                         5)
 *      DESKTOPCHANGE(     XK_egrave,                        6)
 *      DESKTOPCHANGE(     XK_underscore,                    7)
 *      DESKTOPCHANGE(     XK_ccedilla,                      8)
 *      DESKTOPCHANGE(     XK_agrave,                        9)*
 */
#define DESKTOPCHANGE(K,N) \
{  MODKEY ,                     K,                          changeworkspace, {.i=N}}, \
{  MODKEY|SHIFT,                K,                          sendtoworkspace, {.i=N}},

static key keys[] = {
    /* modifier 				key 						function 		argument */

	// Hardware Keys -----------
	{ 0, 						XF86XK_AudioMute, 			start, {.com = mutevol } },
	{ 0, 						XF86XK_AudioMicMute, 		start, {.com = mutemic } },
	{ 0, 						XF86XK_AudioLowerVolume, 	start, {.com = downvol } },
	{ 0, 						XF86XK_AudioRaiseVolume, 	start, {.com = upvol   } },
	{ 0, 						XF86XK_MonBrightnessUp, 	start, {.com = upbl   } },
	{ 0, 						XF86XK_MonBrightnessDown, 	start, {.com = downbl   } },

	// Print Keys -----------
	{ 0, 						XK_Print, 					start, {.com = shotnow } },
	{ ALTKEY, 					XK_Print, 					start, {.com = shotin5 } },
	{ SHIFT, 					XK_Print, 					start, {.com = shotin10 } },
	{ CONTROL, 					XK_Print, 					start, {.com = shotwin } },
	{ MODKEY, 					XK_Print, 					start, {.com = shotarea } },

	// Terminals -----------
    { MODKEY, 					XK_Return, 					start, {.com = termcmd } },
    { MODKEY|SHIFT, 			XK_Return, 					start, {.com = fullterm } },

	// Launch Apps -----------
    { MODKEY, 					XK_f, 						start, {.com = fmcmd } },
    { MODKEY, 					XK_e, 						start, {.com = editcmd } },
    { MODKEY, 					XK_w, 						start, {.com = webcmd } },
	
	// Rofi Menus -----------
    { ALTKEY, 					XK_F1, 						start, {.com = rofi_cmd } },
    { ALTKEY, 					XK_F2, 						start, {.com = rofi_runcmd } },
    { MODKEY, 					XK_m, 						start, {.com = rofi_mpdcmd } },
    { MODKEY, 					XK_n, 						start, {.com = rofi_nmcmd } },
    { MODKEY, 					XK_b, 						start, {.com = rofi_bluecmd } },
    { MODKEY, 					XK_r, 						start, {.com = rofi_rootcmd } },
    { MODKEY, 					XK_x, 						start, {.com = rofi_powercmd } },
    { MODKEY, 					XK_s, 						start, {.com = rofi_shotcmd } },

	// Misc -----------
    { MODKEY, 					XK_p, 						start, {.com = cpickcmd } },
    { ALTKEY|CONTROL, 			XK_l, 						start, {.com = lockcmd } },
    { ALTKEY|CONTROL, 			XK_m, 						start, {.com = musicmd } },

	// Change current workspace -----------
    DESKTOPCHANGE(              XK_1,                       0)
    DESKTOPCHANGE(              XK_2,                       1)
    DESKTOPCHANGE(              XK_3,                       2)
    DESKTOPCHANGE(              XK_4,                       3)
    DESKTOPCHANGE(              XK_5,                       4)
    DESKTOPCHANGE(              XK_6,                       5)
    DESKTOPCHANGE(              XK_7,                       6)
    DESKTOPCHANGE(              XK_8,                       7)
    DESKTOPCHANGE(              XK_9,                       8)
    DESKTOPCHANGE(              XK_0,                       9)

	// 2BWM Session	-----------
    {  MODKEY |CONTROL,         XK_q,                       twobwm_exit,     {.i=0}},
    {  MODKEY |CONTROL,         XK_r,                       twobwm_restart,  {.i=0}},

    // Focus to next/previous window -----------
    {  MODKEY ,              	XK_Tab,        				focusnext,       {.i=TWOBWM_FOCUS_NEXT}},
    {  MODKEY |SHIFT,        	XK_Tab,        				focusnext,       {.i=TWOBWM_FOCUS_PREVIOUS}},

    // Kill a window -----------
    {  MODKEY ,              	XK_c,         			 	deletewin,       {}},
    {  MODKEY ,              	XK_q,          				deletewin,       {}},

    // Move a window -----------
    /* {  MODKEY ,              XK_k,          movestep,          {.i=TWOBWM_MOVE_UP}},
    {  MODKEY ,              XK_j,          movestep,          {.i=TWOBWM_MOVE_DOWN}},
    {  MODKEY ,              XK_l,          movestep,          {.i=TWOBWM_MOVE_RIGHT}},
    {  MODKEY ,              XK_h,          movestep,          {.i=TWOBWM_MOVE_LEFT}}, */
    {  MODKEY ,              XK_Up,         movestep,          {.i=TWOBWM_MOVE_UP}},
    {  MODKEY ,              XK_Down,       movestep,          {.i=TWOBWM_MOVE_DOWN}},
    {  MODKEY ,              XK_Right,      movestep,          {.i=TWOBWM_MOVE_RIGHT}},
    {  MODKEY ,              XK_Left,       movestep,          {.i=TWOBWM_MOVE_LEFT}},

    // Move a window slower -----------
    /* {  MODKEY |CONTROL,      XK_k,          movestep,          {.i=TWOBWM_MOVE_UP_SLOW}},
    {  MODKEY |CONTROL,      XK_j,          movestep,          {.i=TWOBWM_MOVE_DOWN_SLOW}},
    {  MODKEY |CONTROL,      XK_l,          movestep,          {.i=TWOBWM_MOVE_RIGHT_SLOW}},
    {  MODKEY |CONTROL,      XK_h,          movestep,          {.i=TWOBWM_MOVE_LEFT_SLOW}}, */

    // Resize a window -----------
    /* {  MODKEY |SHIFT,        XK_k,          resizestep,        {.i=TWOBWM_RESIZE_UP}},
    {  MODKEY |SHIFT,        XK_j,          resizestep,        {.i=TWOBWM_RESIZE_DOWN}},
    {  MODKEY |SHIFT,        XK_l,          resizestep,        {.i=TWOBWM_RESIZE_RIGHT}},
    {  MODKEY |SHIFT,        XK_h,          resizestep,        {.i=TWOBWM_RESIZE_LEFT}}, */
    {  MODKEY |SHIFT,        XK_Up,         resizestep,        {.i=TWOBWM_RESIZE_UP}},
    {  MODKEY |SHIFT,        XK_Down,       resizestep,        {.i=TWOBWM_RESIZE_DOWN}},
    {  MODKEY |SHIFT,        XK_Right,      resizestep,        {.i=TWOBWM_RESIZE_RIGHT}},
    {  MODKEY |SHIFT,        XK_Left,       resizestep,        {.i=TWOBWM_RESIZE_LEFT}},

    // Resize a window slower -----------
    /* {  MODKEY |SHIFT|CONTROL,XK_k,          resizestep,        {.i=TWOBWM_RESIZE_UP_SLOW}},
    {  MODKEY |SHIFT|CONTROL,XK_j,          resizestep,        {.i=TWOBWM_RESIZE_DOWN_SLOW}},
    {  MODKEY |SHIFT|CONTROL,XK_l,          resizestep,        {.i=TWOBWM_RESIZE_RIGHT_SLOW}},
    {  MODKEY |SHIFT|CONTROL,XK_h,          resizestep,        {.i=TWOBWM_RESIZE_LEFT_SLOW}}, */

    // Teleport the window to an area of the screen -----------
    // Center:
    {  MODKEY ,              XK_g,          teleport,          {.i=TWOBWM_TELEPORT_CENTER}},
    // Center y:
    {  MODKEY |SHIFT,        XK_g,          teleport,          {.i=TWOBWM_TELEPORT_CENTER_Y}},
    // Center x:
    {  MODKEY |CONTROL,      XK_g,          teleport,          {.i=TWOBWM_TELEPORT_CENTER_X}},
    // Top left:
    {  MODKEY ,              XK_h,          teleport,          {.i=TWOBWM_TELEPORT_TOP_LEFT}},
    // Top right:
    {  MODKEY ,              XK_k,          teleport,          {.i=TWOBWM_TELEPORT_TOP_RIGHT}},
    // Bottom left:
    {  MODKEY ,              XK_j,          teleport,          {.i=TWOBWM_TELEPORT_BOTTOM_LEFT}},
    // Bottom right:
    {  MODKEY ,              XK_l,          teleport,          {.i=TWOBWM_TELEPORT_BOTTOM_RIGHT}},

    // Resize while keeping the window aspect ----------
    {  MODKEY |ALTKEY,       XK_Right,      resizestep_aspect, {.i=TWOBWM_RESIZE_KEEP_ASPECT_GROW}},
    {  MODKEY |ALTKEY,       XK_Left,       resizestep_aspect, {.i=TWOBWM_RESIZE_KEEP_ASPECT_SHRINK}},

    // Maximize (ignore offset and no EWMH atom)
    {  MODKEY |SHIFT,        XK_m,          maximize,          {}},

    // Full screen (disregarding offsets and adding EWMH atom)
    {  MODKEY |SHIFT ,       XK_f,          fullscreen,        {}},

    // Maximize vertically
    {  MODKEY ,              XK_v,          maxvert_hor,       {.i=TWOBWM_MAXIMIZE_VERTICALLY}},

    // Maximize horizontally
    {  MODKEY |SHIFT,        XK_v,          maxvert_hor,       {.i=TWOBWM_MAXIMIZE_HORIZONTALLY}},

    // Maximize and move
    // vertically left
    {  MODKEY |SHIFT,        XK_h,          maxhalf,           {.i=TWOBWM_MAXHALF_VERTICAL_LEFT}},
    // vertically right
    {  MODKEY |SHIFT,        XK_l,          maxhalf,           {.i=TWOBWM_MAXHALF_VERTICAL_RIGHT}},
    // horizontally left
    {  MODKEY |SHIFT,        XK_j,          maxhalf,           {.i=TWOBWM_MAXHALF_HORIZONTAL_BOTTOM}},
    // horizontally right
    {  MODKEY |SHIFT,        XK_k,          maxhalf,           {.i=TWOBWM_MAXHALF_HORIZONTAL_TOP}},
    // fold half vertically
    {  MODKEY |SHIFT|CONTROL,XK_k,          maxhalf,           {.i=TWOBWM_MAXHALF_FOLD_VERTICAL}},
    // fold half horizontally
    {  MODKEY |SHIFT|CONTROL,XK_h,          maxhalf,           {.i=TWOBWM_MAXHALF_FOLD_HORIZONTAL}},
    // unfold vertically
    {  MODKEY |SHIFT|CONTROL,XK_j,          maxhalf,           {.i=TWOBWM_MAXHALF_UNFOLD_VERTICAL}},
    // unfold horizontally
    {  MODKEY |SHIFT|CONTROL,XK_l,          maxhalf,           {.i=TWOBWM_MAXHALF_UNFOLD_HORIZONTAL}},

    // Next/Previous screen
    {  MODKEY ,                             XK_comma,      changescreen,      {.i=TWOBWM_NEXT_SCREEN}},
    {  MODKEY ,                             XK_period,     changescreen,      {.i=TWOBWM_PREVIOUS_SCREEN}},

    // Next/Previous workspace
    {  MODKEY |CONTROL,                     XK_Right,      nextworkspace,     {}},
    {  MODKEY |CONTROL,                     XK_Left,       prevworkspace,     {}},

    // Move to Next/Previous workspace
    {  MODKEY |SHIFT|CONTROL ,              XK_Right,      sendtonextworkspace,{}},
    {  MODKEY |SHIFT|CONTROL ,              XK_Left,       sendtoprevworkspace,{}},

    // Iconify the window
    {  MODKEY ,              XK_i,          hide,              {}},

    // Make the window unkillable
    {  MODKEY ,              XK_a,          unkillable,        {}},

    // Raise or lower a window
    {  MODKEY ,              XK_z,          raiseorlower,      {}},

    // Make the window appear always on top
    {  MODKEY,               XK_t,          always_on_top,     {}},

    // Make the window stay on all workspaces
    {  MODKEY ,              XK_d,          fix,               {}},
	
	// Misc
    {  MODKEY ,              XK_space,                   halfandcentered, {.i=0}},
    {  MODKEY ,              XK_y,                       toggle_sloppy,   {.com = sloppy_switch_cmd}},

    // Move the cursor -----------
    /* {  MODKEY ,              XK_Up,         cursor_move,       {.i=TWOBWM_CURSOR_UP_SLOW}},
    {  MODKEY ,              XK_Down,       cursor_move,       {.i=TWOBWM_CURSOR_DOWN_SLOW}},
    {  MODKEY ,              XK_Right,      cursor_move,       {.i=TWOBWM_CURSOR_RIGHT_SLOW}},
    {  MODKEY ,              XK_Left,       cursor_move,       {.i=TWOBWM_CURSOR_LEFT_SLOW}}, */

    // Move the cursor faster -----------
    /* {  MODKEY |SHIFT,        XK_Up,         cursor_move,       {.i=TWOBWM_CURSOR_UP}},
    {  MODKEY |SHIFT,        XK_Down,       cursor_move,       {.i=TWOBWM_CURSOR_DOWN}},
    {  MODKEY |SHIFT,        XK_Right,      cursor_move,       {.i=TWOBWM_CURSOR_RIGHT}},
    {  MODKEY |SHIFT,        XK_Left,       cursor_move,       {.i=TWOBWM_CURSOR_LEFT}}, */
};

/* ******************** Button definitions ******************** */
// the last argument makes it a root window only event
static Button buttons[] = {
    {  MODKEY ,              XCB_BUTTON_INDEX_1,     mousemotion,     {.i=TWOBWM_MOVE}, false},
    {  MODKEY ,              XCB_BUTTON_INDEX_3,     mousemotion,     {.i=TWOBWM_RESIZE}, false},
    {  0 ,                   XCB_BUTTON_INDEX_3,     start,           {.com = rofi_cmd}, true},
    {  MODKEY|SHIFT ,        XCB_BUTTON_INDEX_1,     changeworkspace, {.i=0}, false},
    {  MODKEY|SHIFT ,        XCB_BUTTON_INDEX_3,     changeworkspace, {.i=1}, false},
    {  MODKEY|ALTKEY ,       XCB_BUTTON_INDEX_1,     changescreen,    {.i=1}, false},
    {  MODKEY|ALTKEY ,       XCB_BUTTON_INDEX_3,     changescreen,    {.i=0}, false}
};
