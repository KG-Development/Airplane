#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AirplaneConfig.h"
#include "Turbine.h"
#include "Gears.h"
#include "Wings.h"
#include "Rudder.h"

#define MAX_STRING 31

typedef int boolean;

struct Config { //basic configuration of the current airplane, can be modified as needed, the functions are fully adaptable

    char callSign[MAX_STRING];

    boolean gearsUp;
    float weight;
    float length;
    float span;

    float cw;

    float hullDiameter;
    int wingsCount;
    int rudderCount;
    int gearsCount;
    int turbineCount;

    float throttleAddValue;
};

PConfig Config_create(float weight, int wingsCount, int rudderCount, int gearsCount, int turbineCount, float throttleAddVlue, char* callSign, float span, float hullDiameter, float length){

    PConfig retVal = (PConfig) malloc(sizeof(struct Config));

    strcpy(retVal->callSign, callSign);
    retVal->cw = 0.3;
    retVal->length = length;
    retVal->hullDiameter = hullDiameter;
    retVal->span = span;
    retVal->gearsCount = gearsCount;
    retVal->gearsUp = 0;
    retVal->rudderCount = rudderCount;
    retVal->throttleAddValue = throttleAddVlue;
    retVal->turbineCount = turbineCount;
    retVal->weight = weight;
    retVal->wingsCount = wingsCount;

    return retVal;
}
void Config_print(PConfig _this){
    printf("Config %s{\n", _this->callSign);
    printf("   GearsUp: %d\n   GearsCount: %d\n\n", _this->gearsUp, _this->gearsCount);
    printf("   Weight: %.2ft\n", _this->weight);
    printf("   WingsCount: %d\n", _this->wingsCount);
    printf("   RudderCount: %d\n", _this->rudderCount);
    printf("   GearsCount: %d\n", _this->gearsCount);
    printf("   TurbineCount: %d\n", _this->turbineCount);
    printf("   ThrottleAddValue: %.1f\n", _this->throttleAddValue);
    printf("   HullDiameter: %.2f\n", _this->hullDiameter);
    printf("   Length: %.2f\n", _this->length);
    printf("   Span: %.2f\n", _this->span);
    printf("   CW: %.2f\n", _this->cw);
    printf("}\n");
}

float Config_getThrottleAddValue(PConfig _this){
    return _this->throttleAddValue;
}

void Config_setThrottletAddValue(PConfig _this, int value){
    _this->throttleAddValue = value;
}

int Config_getWingsCount(PConfig _this){
    return _this->wingsCount;
}

int Config_getGearsCount(PConfig _this){
    return _this->gearsCount;
}

int Config_getTurbineCount(PConfig _this){
    return _this->turbineCount;
}

int Config_getRudderCount(PConfig _this){
    return _this->rudderCount;
}

int Config_getSpan(PConfig _this){
    return _this->span;
}

int Config_getHullDiameter(PConfig _this){
    return _this->hullDiameter;
}

float Config_getCWValue(PConfig _this){
    return _this->cw;
}

void Config_switchGears(PConfig _this){

    switch(_this->gearsUp){
    case 1: _this->gearsUp = 0;
        break;
    case 0: _this->gearsUp = 1;
        break;
    }
}

float Config_getWeight(PConfig _this) {
    return (_this->weight * 1000);
}
