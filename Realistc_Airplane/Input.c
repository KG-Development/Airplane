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
        writeToFile(in);
    }else {
        printf("Error occured while allocation. (Input)\n");
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

    if (_this->choice == readFromIndexFile(2, "hotkeys.flightsim")) {
        Airplane_addThrust(_that);
    }else if (_this->choice == readFromIndexFile(3, "hotkeys.flightsim")) {
        Airplane_removeThrust(_that);
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
    FILE *fp = fopen("hotkeys.flightsim", "wb");
    if (!fp) {
        printf("An error occured while allocation. (Opening file writing).");
        return;
    }
    fwrite(_this, sizeof(struct Input), 1, fp);
    fclose(fp);
}

char readFromIndexFile(int idx, char *filename) {
    char ch[3];
    FILE *fp = fopen(filename, "rb");

    if (fp) {
        fread(ch, idx * sizeof(struct Input), 1, fp);
        fclose(fp);

        return ch[idx - 1];
    }
    return EXIT_FAILURE;
}
