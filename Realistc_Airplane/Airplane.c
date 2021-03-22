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

typedef int boolean;

struct Airplane {
    PConfig conf;

    PWingArr wingArr;
    PRudderArr rudderArr;
    PTurbineArr turbineArr;
    PGearsArr gearsArr;
    PLuftwiderstand widerstand;
    PLights lights;
    PInput input;

    float velocity; //KN
    float thrust;
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
    retVal->thrust = 0;
    retVal->velocity = 0;
    retVal->input = Input_createInstance();

    return retVal;
}

void Airplane_addThrust(PAirplane _this) {
    if(_this->thrust + Config_getThrustAddValue(_this->conf) >= 100) {
        _this->thrust = 100;
        return;
    }
    _this->thrust += Config_getThrustAddValue(_this->conf);
}

void Airplane_removeThrust(PAirplane _this) {
    if(_this->thrust - Config_getThrustAddValue(_this->conf) <= 0){
        _this->thrust = 0;
        return;

    }
    _this->thrust -= Config_getThrustAddValue(_this->conf);
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
    printf("Thrust: %.2f\n", _this->thrust);
}

void Airplane_update(PAirplane _this) {
    Input_callFunctionNeeded(_this->input, _this);
}
