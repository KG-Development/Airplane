#pragma once

typedef struct Input *PInput;
typedef struct Airplane* PAirplane;

PInput Input_createInstance();

void Input_UserInput(PInput _this);
void Input_callFunctionNeeded(PInput _this, PAirplane _that);
char Input_getter(PInput _this);

void writeToFile(PInput _this);
char readFromIndexFile(int idx, const char *filename);

void Input_print(PInput _this);
