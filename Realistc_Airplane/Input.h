#pragma once

#include "Airplane.h"

typedef struct Input *PInput;

PInput Input_createInstance();

void Input_UserInput(PInput _this);
void Input_callFunctionNeeded(PInput _this, PAirplane _that);
char Input_getter(PInput _this);

void Input_print(PInput _this);
