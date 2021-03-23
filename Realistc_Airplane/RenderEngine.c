#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "myconio.h"
#include "RenderEngine.h"

#define MAX_X 29
#define MAX_Y 119

struct RenderEngine{

    char field[MAX_Y][MAX_X];
};


PRenderEngine RenderEngine_create() {
    PRenderEngine retVal = (PRenderEngine) malloc(sizeof(struct RenderEngine));
    RenderEngine_setNull(retVal);
    return retVal;
}

void RenderEngine_readFile(PRenderEngine _this, char* filename) {
        FILE *fp = fopen(filename, "r");

        if(!fp){
            printf("File not found");
            return;
        }

        for(int y = 0; y < MAX_Y; y++){
            for(int x = 0; x < MAX_X; x++){
                fscanf(fp, "%c", &(_this->field[y][x]));
            }
        }
        fclose(fp);
}

void RenderEngine_setNull(PRenderEngine _this) {
    for(int y = 0; y < MAX_Y; y++){
        for(int x = 0; x < MAX_X; x++){
            _this->field[y][x] = 0;
        }
    }
}

void RenderEngine_print(PRenderEngine _this) {
    gotoxy(0, 0);
    for(int y = 0; y < MAX_Y; y++) {
        for(int x = 0; x < MAX_X; x++) {
            putchar(_this->field[y][x]);
        }
    }
}

void StartRampPrototype(PRenderEngine _this){

    for(int f = 0; f < 20; f++){

        int count = 0;
        for(int i = MAX_Y; i >= 0; i--){
            gotoxy(count += 2 + f, i);
            printf("/");
        }
        count = MAX_X;
        for(int i = MAX_Y; i >= 0; i--){
            gotoxy(count -= 2 + f, i);
            printf("\\");
        }
        Sleep(1000);
    }
}
