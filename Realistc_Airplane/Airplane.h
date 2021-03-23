#pragma once


typedef struct Airplane* PAirplane;
typedef struct Lights* PLights;
typedef struct Config* PConfig;
typedef struct Wing* PWing;
typedef struct Wing** PWingArr;

PAirplane Airplane_create();

void Airplane_addThrottle(PAirplane _this);
void Airplane_removeThrottle(PAirplane _this);
float Airplane_getThrottle(PAirplane _this);

void Airplane_Debug_printAllData(PAirplane _this);

void Airplane_update(PAirplane _this);

PLights Airplane_getLights(PAirplane _this);
PConfig Airplane_getConfig(PAirplane _this);

PWing Airplane_getWing(PAirplane _this, int index);
PWingArr Airplane_getWingArr(PAirplane _this);
