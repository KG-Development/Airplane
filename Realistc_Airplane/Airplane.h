#pragma once

<<<<<<< HEAD
=======

>>>>>>> 1472160c052deed25834475ae14886b922deb9ff
typedef struct Airplane* PAirplane;
typedef struct Lights* PLights;
PAirplane Airplane_create();

void Airplane_addThrust(PAirplane _this);
void Airplane_removeThrust(PAirplane _this);

void Airplane_Debug_printAllData(PAirplane _this);

void Airplane_update(PAirplane _this);

PLights Airplane_getLights(PAirplane _this);
