#pragma once

#include "Airplane.h"

typedef struct Turbine* PTurbine;
typedef struct Turbine** PTurbineArr;

PTurbine Turbine_create();
PTurbineArr Turbine_createArr(int count);

float Turbine_getThrust(PTurbine _this);

void Turbine_print(PTurbine _this);
void Turbine_printArr(PTurbineArr _this, int count);

void Turbine_calcValues(PTurbine _this, PAirplane _that);
void Turbine_calcValuesArr(PTurbineArr _this, PAirplane _that, int count);

float Turbine_calcThrust(PTurbine _this, PAirplane _that);
float Turbine_calcRPM(PTurbine _this, PAirplane _that);
float Turbine_calcAirFlow(PTurbine _this, PAirplane _that);
