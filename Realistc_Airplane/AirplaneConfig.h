#pragma once

typedef struct Config* PConfig;

PConfig Config_create(float weight, int wingsCount, int rudderCount, int gearsCount, int turbineCount, float thrustAddVlue, char* callSign, float span, float hullDiameter, float length);
void Config_print(PConfig _this);

void Config_setThrottleAddValue(PConfig _this, int value);

float Config_getThrottleAddValue(PConfig _this);
int Config_getWingsCount(PConfig _this);
int Config_getGearsCount(PConfig _this);
int Config_getTurbineCount(PConfig _this);
int Config_getRudderCount(PConfig _this);
int Config_getSpan(PConfig _this);
int Config_getHullDiameter(PConfig _this);
float Config_getCWValue(PConfig _this);

void Config_switchGears(PConfig _this);
float Config_getWeight(PConfig _this);
