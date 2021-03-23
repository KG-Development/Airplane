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
float AirplaneMath_culcFlaps(int state){

    switch(state){
    case 0:
        return 0;
    case 1:
        return 0.35;
    case 2:
        return 0.57;
    case 3:
        return 0.71;
    case 4:
        return 1;
    default: printf("Not a Valid state for Flaps");
    }
    return -1;
}
