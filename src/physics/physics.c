#include <float.h>
#include <math.h>
#include "physics.h"

int Physics_init(void *self) {
    check_mem(self);
    return 1;
error:
    return 0;
}

Object PhysicsProto = {
    .init = Physics_init
};

