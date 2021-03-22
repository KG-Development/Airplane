#pragma once

typedef struct Field* PField;
typedef struct HeaderFooter* PHeaderFooter;
typedef struct Menu* PMenu;

void screen(int Fc, int Bc);

///MENU///

PMenu Menu_create(int fc, int bc);

void Menu_addField(PMenu _this, int fc, int bc, char sign, char* txt);
void Menu_print(PMenu _this);

int Menu_getFc(PMenu _this);
int Menu_getBc(PMenu _this);

char Menu_input(PMenu _this);
///Header Footer///

PHeaderFooter HeaderFooter_create();

void HeaderFooter_print(PHeaderFooter _this, int fc, int bc);

void HeaderFooter_setHeader(PHeaderFooter _this, char* txt);
void HeaderFooter_setFooter(PHeaderFooter _this, char* txt);

int HeaderFooter_isHeader(PHeaderFooter _this);
int HeaderFooter_isFooter(PHeaderFooter _this);
///Field///

PField Field_create(int fc, int bc, char sign, char* txt);

void printField(PField field, int topY, int bottomY);
void printFieldArr(PField field[], int noe);
