#include "Input.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Input {
    char choice;

    char addThrottle;
    char subThrottle;
};

PInput Input_createInstance() {
    PInput in = (PInput)malloc(sizeof(struct Input));

    if (in) {
        in->choice = '0'; //default value (used for debugging, not really needed)
        in->addThrottle = 'a';
        in->subThrottle = 's';
    }else {
        printf("Error occured while allocation. (Input)\n");
        return;
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

    if (_this->choice == _this->addThrottle) {
        Airplane_addThrust(_that);
    }else if (_this->choice == _this->subThrottle) {
        Airplane_removeThrust(_that);
    }else {
        printf("Error. Or wrong input.(Input)\n");
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
