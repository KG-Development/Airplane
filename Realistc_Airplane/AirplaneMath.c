#include <math.h>
#include "AirplaneMath.h"
#include <stdio.h>
#include <stdlib.h>

float AirplaneMath_uplift(float airtight, float velocity, float cl, float span, float dynamicPressure, float weight){

    float upLift = (0.5 * airtight * velocity * cl * (dynamicPressure * dynamicPressure)) / weight;

    return upLift;
}

float AirplaneMath_liftCoefficient(float flapAgnle){

    return (flapAgnle * 5.16) + 0.2;
}
float AirplaneMath_culcDynamicPressure(float airtight, float flowVelocity){

    return (airtight / 2.0) * flowVelocity;
}
