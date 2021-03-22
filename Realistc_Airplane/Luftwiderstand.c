#include <stdio.h>
#include <stdlib.h>
#include "Luftwiderstand.h"

//Formel Luftwiderstand Kraft FL = (1/2) * gl * cw * A * v^2_RL
//cw = Strömungswiderstandskoeffizient
//V^2_RL = Luftgeschwindigkeit (relativ zum quadrat)
//gl = Luftdichte
//A = Querschnittsfläche Fahrzeug

struct Luftwiderstand {
    float cw;
    float v2RL;
    float gl;
    float A;

    float kraft;
};

void Luftwiderstand_set(PLuftwiderstand _this) {
    _this->gl = 1.2041;
    _this->A = 35.8;
    _this->v2RL = 15 * 15;
}

PLuftwiderstand Luftwiderstand_berechneKraft(float cw) {
    PLuftwiderstand w = (PLuftwiderstand)malloc(sizeof(struct Luftwiderstand));
    Luftwiderstand_set(w);

    w->kraft = (1/2.0) * w->gl * cw * w->A * w->v2RL;
    return w;
}

void Luftwiderstand_print(PLuftwiderstand _this) {
    printf("Luftwiderstand Kraft {\n");
    printf("   Kraft: %.2f\n", _this->kraft);
    printf("}\n");
}
