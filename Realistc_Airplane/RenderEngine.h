#pragma once

typedef struct RenderEngine* PRenderEngine;

PRenderEngine RenderEngine_create();
void RenderEngine_setNull(PRenderEngine _this);
void RenderEngine_print(PRenderEngine _this);

void RenderEngine_readFile(PRenderEngine _this, char* filename);

void StartRampPrototype(PRenderEngine _this);
