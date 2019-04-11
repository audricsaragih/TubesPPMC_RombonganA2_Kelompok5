#ifndef LIB3_H
#define LIB3_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tampilkanLayout(char layout[40][40][2], int brs, int klm);
void tampilkanRouting(char routing[40][40], int brs, int klm);
void load(char PCB_layout[40][40][3], char PCB_routing[40][40]);
#endif

