#pragma once

typedef struct Lights* PLights;

PLights Lights_create();
void Lights_print(PLights _this);

void Lights_switchCockpitLights(PLights _this);
void Lights_switchLandinLights(PLights _this);
void Lights_switchBlinkLights(PLights _this);
void Lights_switchTaxiLights(PLights _this);
void Lights_switchNavLights(PLights _this);
