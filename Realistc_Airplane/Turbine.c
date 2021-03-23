#include <stdio.h>
#include <stdlib.h>
#include "Turbine.h"

/*
S = m1(c9 - c0)
S  = Schub in Newton (Schub bei CFM56-5B4 = 120 kN, Also A320 Neo = Schub 120 kn bei Throttle 100%)
M1 = Luftmassestrom in kg/s
C9 = Gasaustrittsgeschwindigkeit in m/s
C0 = Fluggeschwindigkeit in m/s

nv = 2C0 / c0 + c9
nv = Vortriebswirkungsgrad
*/

typedef int boolean;

struct Turbine{
    float rpm;
    float damage;
    boolean fire;

    boolean isOn;

    float thrust;
    float airFlowPerSecond;
};

PTurbine Turbine_create(){
    PTurbine retVal = (PTurbine) malloc(sizeof(struct Turbine));

    retVal->damage = 0.0;
    retVal->isOn = 0;
    retVal->fire = 0;
    retVal->rpm = 0;
    retVal->thrust = 0;
    retVal->airFlowPerSecond = 0;

    return retVal;
}

PTurbineArr Turbine_createArr(int count) {
    PTurbineArr retVal = (PTurbineArr) malloc(count * sizeof(PTurbine));

    for(int i = 0; i < count; i++){
        retVal[i] = Turbine_create();
    }
    return retVal;
}

void Turbine_print(PTurbine _this) {
    printf("   RPM: %.2f rpm\n", _this->rpm);
    printf("   Fire: %d\n", _this->fire);
    printf("   Damage: %.2f\n", _this->damage);
    printf("   Current thrust: %.2f Newton\n", _this->thrust);
    printf("   Air Flow per second: %.2f kg/s\n", _this->airFlowPerSecond);
}

void Turbine_printArr(PTurbineArr _this, int count) {
    for(int i = 0; i < count; i++){
        printf("Turbine %d {\n", i + 1);
        Turbine_print(_this[i]);
        printf("}\n");
    }
}

void Turbine_calcValues(PTurbine _this, PAirplane _that) {
    _this->thrust = Turbine_calcThrust(_this, _that);
    _this->rpm = Turbine_calcRPM(_this, _that);
    _this->airFlowPerSecond = Turbine_calcAirFlow(_this, _that);
}

float Turbine_calcThrust(PTurbine _this, PAirplane _that) {
    if (_this->isOn == 0 && Airplane_getThrottle(_that)) { //engine start up
        _this->isOn++;
        return 1200;
    }
    if ((_this->thrust * Airplane_getThrottle(_that)) >= 120000) {
        return _this->thrust = 120000.0;  //the thrust cant be higher than 120 kN
    }
    return _this->thrust = _this->thrust * Airplane_getThrottle(_that);
}

void Turbine_calcValuesArr(PTurbineArr _this, PAirplane _that, int count) {
    for(int i = 0; i < count; i++){
        Turbine_calcValues(_this[i], _that);
    }
}

float Turbine_calcRPM(PTurbine _this, PAirplane _that) {
    if (_this->isOn == 1) { //engine start up
        _this->isOn++;
        return 144.60;
    }
    if ((_this->rpm * Airplane_getThrottle(_that)) >= 14460) {
        return _this->rpm = 14460.0;  //the rpm cant be higher than 14460 HP RPM HP = High Pressure
    }
    return _this->rpm = _this->rpm * Airplane_getThrottle(_that);
}

float Turbine_calcAirFlow(PTurbine _this, PAirplane _that) {
    if (_this->isOn == 2) {
        _this->isOn++;
        return 3.97;
    }
    if ((_this->airFlowPerSecond * Airplane_getThrottle(_that)) >= 397) {
        return _this->airFlowPerSecond = 397;  //the air flow cant be higher than 397 kg / s
    }
    return _this->airFlowPerSecond = _this->airFlowPerSecond * Airplane_getThrottle(_that);
}
