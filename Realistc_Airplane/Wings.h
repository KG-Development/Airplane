#pragma once

typedef struct Wing* PWing;
typedef struct Wing** PWingArr;

PWing Wings_create();
PWingArr Wings_createArr(int count);

void Wings_print(PWing _this);
void Wings_printArr(PWingArr _this, int count);

void Wings_addFlaps(PWing _this);
void Wings_removeFlaps(PWing _this);

int Wings_getFlaps(PWing _this);
void Wings_addFlapsArr(PWingArr _this, int count);
void Wings_removeFlapsArr(PWingArr _this, int count);
