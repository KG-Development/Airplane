#pragma once


float AirplaneMath_uplift(float airtight, float velocity, float cl, float span, float dynamicPressure);
float AirplaneMath_liftCoefficient(float flapAgnle);
float AirplaneMath_culcDynamicPressure(float airtight, float flowVelocity);
