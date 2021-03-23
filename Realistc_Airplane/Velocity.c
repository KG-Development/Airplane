#include <stdio.h>
#include <stdlib.h>
#include "Velocity.h"

float Velocity_getVelocity(int init, PAirplane _this, int time, float acc) {
    float vel = time * acc + init;

    if (vel >= 905) {
        vel = 905;
    }

    return vel;
}
