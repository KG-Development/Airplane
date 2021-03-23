#include "Input.h"
#include "Airplane.h"
#include "Light.h"
#include "AirplaneConfig.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define NUM_OF_HOTKEYS 9

struct Input {
    char choice;

    char addThrottle;
    char subThrottle;

    char taxiLightsSwitch;
    char navLightsSwitch;
    char blinkLightsSwitch;
    char landingLightsSwitch;
    char cockpitLightSwitch;
    char gears;
};

PInput Input_createInstance() {
    PInput in = (PInput)malloc(sizeof(struct Input));

    if (in) {
        in->choice = '0'; //default value (used for debugging, not really needed)
        in->addThrottle = 'a';
        in->subThrottle = 's';
        in->taxiLightsSwitch = '1';
        in->navLightsSwitch = '2';
        in->blinkLightsSwitch = '3';
        in->landingLightsSwitch = '4';
        in->cockpitLightSwitch = '5';
        in->gears = 'g';
        writeToFile(in);
    }else {
        printf("Error occurred while allocation. (Input)\n");
        return NULL;
    }
    return in;
}

void Input_UserInput(PInput _this) {
    if(kbhit()) {   //if the keyboard is hit, the user gets an input, it keyboard is not hit, the last choice is used
        _this->choice = getch();
    }
}

void Input_callFunctionNeeded(PInput _this, PAirplane _that) {
    Input_UserInput(_this);
    const char* filename = ".\\hotkeys\\hotkeys.flightsim";

    if (_this->choice == readFromIndexFile(2, filename)) {
        Airplane_addThrottle(_that);
    }else if (_this->choice == readFromIndexFile(3, filename)) {
        Airplane_removeThrottle(_that);

    }else if(_this->choice == readFromIndexFile(4, filename)) {
        Lights_switchTaxiLights(Airplane_getLights(_that));

    }else if(_this->choice == readFromIndexFile(5, filename)) {
        Lights_switchNavLights(Airplane_getLights(_that));

    }else if(_this->choice == readFromIndexFile(6, filename)) {
        Lights_switchBlinkLights(Airplane_getLights(_that));

    }else if(_this->choice == readFromIndexFile(7, filename)) {
        Lights_switchLandinLights(Airplane_getLights(_that));

    }else if(_this->choice == readFromIndexFile(8, filename)) {
        Lights_switchCockpitLights(Airplane_getLights(_that));

    }else if (_this->choice == readFromIndexFile(9, filename)) {
        Config_switchGears(Airplane_getConfig(_that));
    }else if (_this->choice == '0'){


    }else {
        printf("Error. Or wrong input.(Input) choice: %c\n", _this->choice);
    }
}

char Input_getter(PInput _this) {
    return (_this->choice);
}

void Input_print(PInput _this) {
    printf("Input {\n");
    printf("  User Choice: %c\n", Input_getter(_this));
    printf("}\n");
}

void writeToFile(PInput _this) {
    FILE *fp = fopen(".\\hotkeys\\hotkeys.flightsim", "wb");
    if (!fp) {
        printf("An error occurred while allocation. (Opening file writing).");
        return;
    }
    fwrite(_this, sizeof(struct Input), 1, fp);
    fclose(fp);
}

char readFromIndexFile(int idx, const char *filename) {
    char ch[NUM_OF_HOTKEYS];
    FILE *fp = fopen(filename, "rb");

    if (fp) {
        fread(ch, idx * sizeof(struct Input), 1, fp);
        fclose(fp);

        return ch[idx - 1];
    }
    return EXIT_FAILURE;
}
