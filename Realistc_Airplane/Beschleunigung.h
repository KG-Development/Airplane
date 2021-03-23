#pragma once

#include "Airplane.h"
#include "Turbine.h"

typedef struct Acceleration *PAcceleration;

PAcceleration Acceleration_createInstance();

float Acceleration_getter(PAcceleration _this);
void Acceleration_setter(PAcceleration _this, float val);

void Acceleration_createInitialValue(PAcceleration _this);
float Acceleration_getCurrentAcceleration(PAcceleration _this, PAirplane _that, float newtonOfTurbines);

void Acceleration_print(PAcceleration _this);
