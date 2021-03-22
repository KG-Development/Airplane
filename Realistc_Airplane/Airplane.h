#pragma once


typedef struct Airplane* PAirplane;
typedef struct Lights* PLights;
typedef struct Config* PConfig;

PAirplane Airplane_create();

void Airplane_addThrust(PAirplane _this);
void Airplane_removeThrust(PAirplane _this);

void Airplane_Debug_printAllData(PAirplane _this);

void Airplane_update(PAirplane _this);

PLights Airplane_getLights(PAirplane _this);
PConfig Airplane_getConfig(PAirplane _this);
