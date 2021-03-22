#include <stdio.h>
#include <stdlib.h>
#include "Airplane.h"
#include "Turbine.h"
#include "Gears.h"
#include "Wings.h"
#include "Rudder.h"
#include "AirplaneConfig.h"
#include "Input.h"
#include "Light.h"
#include "Fuel.h"
#include "Luftwiderstand.h"
#include "Menu.h"
#include "myconio.h"
#include "RenderEngine.h"

int main() {
    PConfig config = Config_create(42, 4, 1, 3, 2, 1, "A 320 Neo", 35.80, 3.96, 32);
    PAirplane airplane = Airplane_create(config);
    PMenu menu = Menu_create(GREEN, BLACK);

    Menu_addField(menu, GREEN, BLACK, 's', "Start");
    Menu_addFooter(menu, "Hello World");
    Menu_addHeader(menu, "Fly");
    Menu_print(menu);
    Menu_input(menu);

    system("cls");  //temp until new sol has been found

    Airplane_update(airplane);  //calling the update function (later this must be a loop)
    Airplane_Debug_printAllData(airplane);

    printf("\n\n");
    PRenderEngine render = RenderEngine_create();
    RenderEngine_readFile(render, ".\\drawing\\draw1.txt");
    RenderEngine_print(render);
}
