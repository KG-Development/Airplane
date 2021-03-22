#include <stdio.h>
#include <stdlib.h>
#include "GameManager.h"

typedef int boolean;

struct GameManager{
    boolean gameRun;
};

PGameManager GameManager_create(){

    PGameManager retVal = (PGameManager) malloc(sizeof(struct GameManager));
    retVal->gameRun = 0;
    return retVal;
}
void GameManager_print(PGameManager _this){

    printf("GameManager {\n");
    printf("   gameRun: %d\n", _this->gameRun);
    printf("}\n");
}
boolean GameManager_getGameRun(PGameManager _this){

    return _this->gameRun;
}
void GameManager_setGameRun(PGameManager _this, boolean state){

    if(state < 0 ||state > 1) return;

    _this->gameRun = state;
}
