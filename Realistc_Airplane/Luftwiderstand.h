#pragma once

#include "AirplaneConfig.h"
#include "Turbine.h"
#include "Gears.h"
#include "Wings.h"
#include "Rudder.h"

#define Current_Air_Velocity 15

typedef struct Luftwiderstand *PLuftwiderstand;

PLuftwiderstand Luftwiderstand_berechneKraft(float cw);
void Luftwiderstand_set(PLuftwiderstand _this);

void Luftwiderstand_print(PLuftwiderstand _this);
