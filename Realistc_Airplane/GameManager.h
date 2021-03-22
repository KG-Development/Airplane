#pragma once

typedef struct GameManager* PGameManager;

PGameManager GameManager_create();

void GameManager_print();

int GameManager_getGameRun(PGameManager _this);
void GameManager_setGameRun(PGameManager _this, boolean state);
