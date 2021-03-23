#include <stdio.h>
#include <stdlib.h>
#include "Beschleunigung.h"
#include "AirplaneConfig.h"

struct Acceleration {
    float F;    //f are the m^2/s it's calculated using the formula f = m * a
    float initialF;
};

PAcceleration Acceleration_createInstance() {
    PAcceleration acc = (PAcceleration)malloc(sizeof(struct Acceleration));
    if (!acc) {
        printf("Error occurred while allocation. (Acceleration)");
        return NULL;
    }
    acc->F = 0;
    acc->initialF = 0;
    return acc;
}

float Acceleration_getter(PAcceleration _this) {
    return _this->F;
}

void Acceleration_setter(PAcceleration _this, float val) {
    _this->F = val;
}

void Acceleration_createInitialValue(PAcceleration _this) {
    _this->initialF = 9.81;    //gravitational forces (9.81)
}

float Acceleration_getCurrentAcceleration(PAcceleration _this, PAirplane _that, float newtonOfTurbines) {
    _this->F = newtonOfTurbines / Config_getWeight(Airplane_getConfig(_that));
    return _this->F;
}

void Acceleration_print(PAcceleration _this) {
    printf("Acceleration: {\n");
    printf("  Acceleration: %.2f\n", _this->F);
    printf("}\n");
}
