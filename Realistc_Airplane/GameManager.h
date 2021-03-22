#pragma once

typedef struct GameManager* PGameManager;

PGameManager GameManager_create();

void GameManager_print();

int GameManager_getGameRun(PGameManager _this)
