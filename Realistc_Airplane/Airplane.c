#include <stdio.h>
#include <stdlib.h>
#include "Airplane.h"
#include "Turbine.h"
#include "Gears.h"
#include "AirplaneConfig.h"
#include "Wings.h"
#include "Rudder.h"
#include "Luftwiderstand.h"
#include "Light.h"
#include "Input.h"
#include "AirplaneMath.h"
#include "Beschleunigung.h"


typedef int boolean;

float getThrustCombined(PAirplane _this, int count);

struct Airplane {
    PConfig conf;

    PWingArr wingArr;
    PRudderArr rudderArr;
    PTurbineArr turbineArr;
    PGearsArr gearsArr;
    PLuftwiderstand widerstand;
    PLights lights;
    PInput input;
    PAcceleration acceleration;

    float velocity; //KN
    float throttle;
};

float converterKn(float velocity) {
    return (velocity / 1.852);
}

float convertKmh(float velocity) {
    return (velocity * 1.852);
}

PAirplane Airplane_create(PConfig conf) {

    PAirplane retVal = (PAirplane) malloc(sizeof(struct Airplane));

    retVal->conf = conf;
    retVal->turbineArr = Turbine_createArr(Config_getTurbineCount(retVal->conf));
    retVal->gearsArr = Gears_createArr(Config_getGearsCount(retVal->conf));
    retVal->wingArr = Wings_createArr(Config_getWingsCount(retVal->conf));
    retVal->rudderArr = Rudder_createArr(Config_getRudderCount(retVal->conf));
    retVal->widerstand = Luftwiderstand_berechneKraft(Config_getCWValue(retVal->conf));
    retVal->lights = Lights_create();
    retVal->throttle = 100;
    retVal->velocity = 0;
    retVal->input = Input_createInstance();
    retVal->acceleration = Acceleration_createInstance();

    Acceleration_createInitialValue(retVal->acceleration);

    return retVal;
}

void Airplane_addThrottle(PAirplane _this) {
    if(_this->throttle + Config_getThrottleAddValue(_this->conf) >= 100) {
        _this->throttle = 100;
        return;
    }
    _this->throttle += Config_getThrottleAddValue(_this->conf);
}

void Airplane_removeThrottle(PAirplane _this) {
    if(_this->throttle - Config_getThrottleAddValue(_this->conf) <= 0){
        _this->throttle = 0;
        return;

    }
    _this->throttle -= Config_getThrottleAddValue(_this->conf);
}

void Airplane_Debug_printAllData(PAirplane _this) {
    Config_print(_this->conf);
    Turbine_printArr(_this->turbineArr, Config_getTurbineCount(_this->conf));
    Gears_printArr(_this->gearsArr, Config_getGearsCount(_this->conf));
    Wings_printArr(_this->wingArr, Config_getWingsCount(_this->conf));
    Rudder_printArr(_this->rudderArr, Config_getRudderCount(_this->conf));
    Lights_print(_this->lights);
    Luftwiderstand_print(_this->widerstand);
    Input_print(_this->input);
    Acceleration_print(_this->acceleration);
    printf("Throttle: %.2f \n", _this->throttle);
    printf("Flaps calc: %.2f\n", AirplaneMath_culcFlaps(Wings_getFlaps(Airplane_getWing(_this, 0))));
    printf("\nUplift %.2f m/s", AirplaneMath_uplift(AirResuspension_getAirtight(_this->widerstand), 250, AirplaneMath_liftCoefficient(0), Config_getSpan(_this->conf), AirplaneMath_culcDynamicPressure(AirResuspension_getAirtight(_this->widerstand), AirResuspension_getAirvelocity(_this->widerstand)), Config_getWeight(_this->conf)));
}

void Airplane_update(PAirplane _this) {
    for(int i = 0; i < 1000; i++)
    Input_callFunctionNeeded(_this->input, _this);
    Turbine_calcValuesArr(_this->turbineArr, _this, Config_getTurbineCount(_this->conf));
    float acc = Acceleration_getCurrentAcceleration(_this->acceleration, _this, getThrustCombined(_this, Config_getTurbineCount(_this->conf)));
    Acceleration_setter(_this->acceleration, acc);
}

float getThrustCombined(PAirplane _this, int count) {
    float th = 0;
    for (int i = 0; i < count; i++) {
        th = th + Turbine_getThrust(_this->turbineArr[i]);
    }
    return th;
}

PLights Airplane_getLights(PAirplane _this){
    return _this->lights;
}
PConfig Airplane_getConfig(PAirplane _this){
    return _this->conf;
}

float Airplane_getThrottle(PAirplane _this) {
    return (_this->throttle);
}
PWing Airplane_getWing(PAirplane _this, int index){

    if(index > Config_getWingsCount(_this->conf)) exit(EXIT_FAILURE);

    return _this->wingArr[index];
}
PWingArr Airplane_getWingArr(PAirplane _this){
    return _this->wingArr;
}
