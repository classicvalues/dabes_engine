#ifndef __vrect_h
#define __vrect_h
#include "vpoint.h"

typedef struct VProjection {
    double min;
    double max;
} VProjection;

int VProjection_does_overlap(VProjection a, VProjection b);
double VProjection_get_overlap(VProjection a, VProjection b);

typedef struct VRect {
    VPoint tl;
    VPoint tr;
    VPoint br;
    VPoint bl;
} VRect;

static const VRect VRectZero = {{0,0},{0,0},{0,0},{0,0}};

VRect VRect_from_xywh(double x, double y, double w, double h);
VRect VRect_inset(VRect rect, double inset);
VRect VRect_round_out(VRect rect);

VPoint VRect_center(VRect box);
VPoint VRect_vertex(VRect box, unsigned int index);
VRect VRect_rotate(VRect box, VPoint pivot, double angle_in_rads);
VRect VRect_move(VRect box, VPoint move);

VProjection VRect_project_onto(VRect box, VPoint axis);
void VRect_find_axes(VRect box, VPoint *axes);
int VRect_collision(VRect a, VRect b, VPoint *mtv);
VPoint VRect_poc(VRect a, VRect b);
int VRect_contains_point(VRect box, VPoint point);
VRect VRect_bounding_box(VRect rect);
int VRect_is_equal(VRect *a, VRect *b);
VPoint VRect_cnormal_from_mtv(VRect normal_for, VRect against,
        VPoint mtv);

#ifdef DABES_SDL
VRect VRect_from_SDL_Rect(SDL_Rect rect);
#endif

VPointRel VPoint_rect_rel(VPoint point, VRect rect);

#endif
