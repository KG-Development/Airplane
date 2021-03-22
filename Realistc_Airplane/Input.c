#include "Input.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Input {
    char choice;
    char lastChoice;
};

PInput Input_createInstance() {
    PInput in = (PInput)malloc(sizeof(struct Input));

    if (in) {
        in->choice = '0'; //default value (used for debugging, not really needed)
        in->lastChoice = in->choice;
    }else {
        printf("Error occured while allocation. (Input)\n");
        return;
    }
    return in;
}

void Input_UserInput(PInput _this) {
    if(kbhit()) {   //if the keyboard is hit, the user gets an input, it keyboard is not hit, the last choice is used
        _this->choice = getch();
        _this->lastChoice = _this->choice;
    }
}

int Input_checkUserInput(PInput _this) {
    return !(_this->choice == 'a' || _this->choice == 's');
}

void Input_callFunctionNeeded(PInput _this, PAirplane _that) {
    Input_UserInput(_this);

    switch(_this->choice) {

        case 'a':
                  Airplane_addThrust(_that);
                  break;

        case 's':
                  Airplane_removeThrust(_that);
                  break;

        default:
                  break;
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
