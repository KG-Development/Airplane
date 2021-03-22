#include <stdio.h>
#include <stdlib.h>
#include "Turbine.h"

/*
S = m1(c9 - c0)
S  = Schub in Newton
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

    float thrust;
    float airMassFlow;
    float gasOutletVelocity;
    float velocity;
    float advanceEfficiency
};

PTurbine Turbine_create(){

    PTurbine retVal = (PTurbine) malloc(sizeof(struct Turbine));
    retVal->damage = 0.0;
    retVal->fire = 0;
    retVal->rpm = 0;

    return retVal;
}
PTurbineArr Turbine_createArr(int count){

    PTurbineArr retVal = (PTurbineArr) malloc(count * sizeof(PTurbine));

    for(int i = 0; i < count; i++){
        retVal[i] = Turbine_create();
    }
    return retVal;
}

void Turbine_print(PTurbine _this){

    printf("   RPM: %.2f\n", _this->rpm);
    printf("   Fire: %d\n", _this->fire);
    printf("   Damage: %.2f\n", _this->damage);
}
void Turbine_printArr(PTurbineArr _this, int count){

    for(int i = 0; i < count; i++){
        printf("Turbine %d {\n", i + 1);
        Turbine_print(_this[i]);
        printf("}\n");
    }
}
