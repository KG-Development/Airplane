#include <stdlib.h>
#include <stdio.h>
#include "Light.h"

typedef int boolean;

struct Lights{

    boolean taxiLights;
    boolean navLights;
    boolean blinkLights;
    boolean landingLights;
    boolean cockpitLight;
    int powerCockpitLight;
};

PLights Lights_create(){

    PLights retVal = (PLights) malloc(sizeof(struct Lights));

    retVal->taxiLights = 0;
    retVal->navLights = 0;
    retVal->blinkLights = 0;
    retVal->landingLights = 0;
    retVal->cockpitLight = 0;
    retVal->powerCockpitLight = 0;
    return retVal;
}

void Lights_switchCockpitLights(PLights _this){

    switch(_this->cockpitLight){
    case 1: _this->cockpitLight = 0;
        break;
    case 0: _this->cockpitLight = 1;
        break;
    }
}
void Lights_switchLandinLights(PLights _this){

    switch(_this->landingLights){
    case 1: _this->landingLights = 0;
        break;
    case 0: _this->landingLights = 1;
        break;
    }
}
void Lights_switchBlinkLights(PLights _this){

    switch(_this->blinkLights){
    case 1: _this->blinkLights = 0;
        break;
    case 0: _this->blinkLights = 1;
        break;
    }
}
void Lights_switchTaxiLights(PLights _this){

    switch(_this->taxiLights){
    case 1: _this->taxiLights = 0;
        break;
    case 0: _this->taxiLights = 1;
        break;
    }
}
void Lights_switchNavLights(PLights _this){

    switch(_this->navLights){
    case 1: _this->navLights = 0;
        break;
    case 0: _this->navLights = 1;
        break;
    }
}

void Lights_print(PLights _this){

    printf("Lights {\n");
    printf("   TaxiLights: %d\n", _this->taxiLights);
    printf("   NavLights: %d\n", _this->navLights);
    printf("   BlinkLights: %d\n", _this->blinkLights);
    printf("   LandingLights: %d\n", _this->landingLights);
    printf("   CockpitLights: %d\n", _this->cockpitLight);
    printf("   PowerCockpitLight: %d\n", _this->powerCockpitLight);
    printf("}\n");
}
