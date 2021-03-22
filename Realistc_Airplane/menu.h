#pragma once

typedef struct Field* PField;
typedef struct HeaderFooter* PHeaderFooter;
typedef struct Menu* PMenu;

void screen(int Fc, int Bc); //Draws a full size screen in Color fc and bc

///MENU///

PMenu Menu_create(int fc, int bc); //Create a Menu

void Menu_addField(PMenu _this, int fc, int bc, char sign, char* txt); //Adds a Field to your Menu you can customize your field, input and text
void Menu_print(PMenu _this);   //Prints the Menu

int Menu_getFc(PMenu _this); //Get the Fc
int Menu_getBc(PMenu _this); //Get the Bc

void Menu_addHeader(PMenu _this, char* txt); //Adds a Header to your Menu
void Menu_addFooter(PMenu _this, char* txt); //Adds a Footer to your Menu

char Menu_input(PMenu _this); //While loop until you press a right key from a Field and returns it
///Header Footer///

PHeaderFooter HeaderFooter_create(); //Creates a Header and a Footer its one Struct

void HeaderFooter_print(PHeaderFooter _this, int fc, int bc);   //Prints the Header and Footer

void HeaderFooter_setHeader(PHeaderFooter _this, char* txt); //Set a text to the Header
void HeaderFooter_setFooter(PHeaderFooter _this, char* txt); //Set a text to the Footer

int HeaderFooter_isHeader(PHeaderFooter _this); //Returns the boolean for the Header
int HeaderFooter_isFooter(PHeaderFooter _this); //Returns the boolean for the Footer
///Field///

PField Field_create(int fc, int bc, char sign, char* txt); //Create a Field

void Field_print(PField field, int topY, int bottomY); //Prints the Field
void Field_printArr(PField field[], int noe);   //Prints the Field Array
