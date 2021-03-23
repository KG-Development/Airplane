#include <stdio.h>
#include <stdlib.h>
#include "Velocity.h"

float Velocity_getVelocity(int init, PAirplane _this, int time, float acc) {
    float vel = time * acc;

    printf("\n\n%.2f\n\n", vel);

    return vel;
}
