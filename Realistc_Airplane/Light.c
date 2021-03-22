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
