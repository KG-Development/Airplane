#pragma once

typedef struct Config* PConfig;

PConfig Config_create(float weight, int wingsCount, int rudderCount, int gearsCount, int turbineCount, int thrustAddVlue, char* callSign, float span, float hullDiameter, float length);
void Config_print(PConfig _this);

void Config_setThrustAddValue(PConfig _this, int value);

int Config_getThrustAddValue(PConfig _this);
int Config_getWingsCount(PConfig _this);
int Config_getGearsCount(PConfig _this);
int Config_getTurbineCount(PConfig _this);
int Config_getRudderCount(PConfig _this);
int Config_getSpan(PConfig _this);
int Config_getHullDiameter(PConfig _this);
int Config_getCWValue(PConfig _this);
