#include <stdio.h>
#include <stdlib.h>
#include "Wings.h"

typedef int boolean;

struct Wing{

    float airbreak;
    int flaps;

    boolean fire;
    float damage;
};

PWing Wings_create(){

    PWing retVal = (PWing) malloc(sizeof(struct Wing));
    retVal->airbreak = 0;
    retVal->flaps = 0;
    retVal->fire = 0;
    retVal->damage = 0;

    return retVal;
}
PWingArr Wings_createArr(int count){

    PWingArr retVal = (PWingArr) malloc(count * sizeof(PWing));

    for(int i = 0; i < count; i++){

        retVal[i] = Wings_create();
    }
    return retVal;
}

void Wings_addFlaps(PWing _this){

    if(_this->flaps == 4) return;
    _this->flaps += 1;
}
void Wings_removeFlaps(PWing _this){
    if(_this->flaps == 0) return;
    _this->flaps -= 1;
}
int Wings_getFlaps(PWing _this){

    return _this->flaps;
}
void Wings_print(PWing _this){

    printf("   Airbreak: %.2f%c\n", _this->airbreak, '%');
    printf("   Flaps: %d\n", _this->flaps);
    printf("   Fire: %d\n", _this->fire);
    printf("   Damage: %.2f\n", _this->damage);
}
void Wings_printArr(PWingArr _this, int count){

    for(int i = 0; i < count; i++){
        printf("Wings %d {\n", i + 1);
        Wings_print(_this[i]);
        printf("}\n");
    }
}

void Wings_addFlapsArr(PWingArr _this, int count){

    for(int i = 0; i < count; i++){
        Wings_addFlaps(_this[i]);
    }
}
void Wings_removeFlapsArr(PWingArr _this, int count){

    for(int i = 0; i < count; i++){
        Wings_removeFlaps(_this[i]);
    }
}
