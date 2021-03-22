#include "menu.h"
#include "myconio.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MENU_MAX_WIDTH 119
#define MENU_MAX_HIGHT 29
#define MENU_MAX_STRING 31
#define MENU_MAX_FIELDS 5
#define MENU_TRUE 1
#define MENU_FALSE 0

struct Field{
    int Fc;
    int Bc;
    char text[MENU_MAX_STRING];
    char sign;
};

struct HeaderFooter{
    char headerText[MENU_MAX_STRING];
    int boolHeader;
    char footerText[MENU_MAX_STRING];
    int boolFooter;
};

struct Menu{
    int Fc;
    int Bc;
    PHeaderFooter headerFooter;
    PField fieldArr[MENU_MAX_FIELDS];
    int fieldNoe;
};
///MENU//

PMenu Menu_create(int fc, int bc){

    if((fc < 0 || fc > 15) && (bc < 0 || bc > 15)) return;

    PMenu retVal = (PMenu) malloc(sizeof(struct Menu));
    retVal->Bc = bc;
    retVal->Fc = fc;
    retVal->headerFooter = HeaderFooter_create();
    retVal->fieldNoe = 0;
    return retVal;
}

void Menu_addField(PMenu _this, int fc, int bc, char sign, char* txt){


    if(_this->fieldNoe > 4) return;

    _this->fieldArr[_this->fieldNoe] = Field_create(fc, bc, sign, txt);
    _this->fieldNoe += 1;

}

int Menu_getFc(PMenu _this){

    return _this->Fc;
}
int Menu_getBc(PMenu _this){
    return _this->Bc;
}

void Menu_print(PMenu _this){

    const int fc = Menu_getFc(_this);
    const int bc = Menu_getBc(_this);

    int topY = 3;
    int bottomY = 3;

    if(menu->headerFooter.boolHeader || menu->headerFooter.boolFooter){
        printHeaderFooter(&menu->headerFooter, fc, bc);
        if(!menu->headerFooter.boolHeader) topY = 0;
        if(!menu->headerFooter.boolFooter) bottomY = 0;
        setWindow(0, topY, MENU_MAX_WIDTH, MENU_MAX_HIGHT - bottomY, fc, bc);
    }else{
        screen(fc, bc);
    }

    printFieldArr(menu->fieldArr, menu->fieldNoe);

    setColorAndBackground(WHITE, BLACK);
}

char Menu_input(PMenu menu){

    char user_input;

    if(!menu->fieldNoe) return 'º';
    do{
        user_input = getch();
    }while(!checkKey(menu->fieldArr, user_input, menu->fieldNoe));

    return user_input;
}
///Header Footer///

PHeaderFooter HeaderFooter_create(){

    PHeaderFooter retVal = (PHeaderFooter) malloc(sizeof(struct HeaderFooter));
    retVal->boolFooter = 0;
    retVal->boolHeader = 0;
    strcpy(retVal->headerText, "samlpe");
    strcpy(retVal->footerText, "samlpe");

    return retVal;
}

void HeaderFooter_setHeader(PHeaderFooter _this, char* txt){

    strcpy(_this->headerText, txt);
    _this->boolHeader = MENU_TRUE;
}
void HeaderFooter_setFooter(PHeaderFooter _this, char* txt){

    strcpy(_this->footerText, txt);
    _this->boolFooter = MENU_TRUE;
}
void HeaderFooter_print(PHeaderFooter _this, int fc, int bc){

    if(hf->boolHeader){
        setWindow(0, 0, MENU_MAX_WIDTH, 2, fc, bc);
        gotoxy(MENU_MAX_WIDTH / 2 - (strlen(_this->headerText) / 2), 1);
        puts(_this->headerText);
    }
    if(hf->boolFooter){
        setWindow(0, MENU_MAX_HIGHT - 2, MENU_MAX_WIDTH, MENU_MAX_HIGHT, fc, bc);
        gotoxy(MENU_MAX_WIDTH / 2 - (strlen(_this->footerText) / 2), 28);
        puts(_this->footerText);
    }
}

int HeaderFooter_isHeader(PHeaderFooter _this){
    return _this->boolHeader;
}
int HeaderFooter_isFooter(PHeaderFooter _this){
    return _this->booleanFooter;
}

///Field///
PField Field_create(int fc, int bc, char sign, char* txt){

    PField retVal = (PField) malloc(sizeof(struct Field));
    retVal->Fc = fc;
    retVal->Bc = bc;
    strcpy(retVal->text, txt);
    retVal->sign = sign;
    return retVal;
}

void printField(TField* field, int topY, int bottomY){

    setWindow(25, topY, 95, bottomY, field->Fc, field->Bc);
    gotoxy(46, (topY + bottomY) / 2);
    printf("Press [%c] %s", field->sign, field->text);
}
void printFieldArr(TField field[], int noe){

    int topY = 5, bottomY = 7;

    for(int idx = 0; idx < noe; idx++){

        printField(&field[idx], topY, bottomY);
        topY += 4;
        bottomY += 4;
    }
}

///Help Function///
void screen(int Fc, int Bc){

    setWindow(0, 0, MENU_MAX_WIDTH, MENU_MAX_HIGHT, Fc, Bc);
}

int checkKey(TField field[], char key, int noe){

    for(int idx = 0; idx < noe; idx++){

        if(key == field[idx].sign) return 1;
    }
    return 0;
}

