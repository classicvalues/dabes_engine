#ifndef __input_h
#define __input_h
#include "../prefix.h"
#include "controller.h"

typedef struct Input {
    Controller *controllers[4];
    int game_quit;
    int debug_scene_draw_grid;
    int cam_reset;
    int cam_zoom;
    int cam_rotate;
    int cam_debug;
    int phys_render;
} Input;

Input *Input_create();
void Input_destroy(Input *input);
void Input_poll(Input *input);
void Input_touch(Input *input, Input *touch_input);
void Input_reset(Input *input);

#endif
