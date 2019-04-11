#ifndef LIB2_H
#define LIB2_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
	int x;
	int y;
}titik;

void routingManual(char PCB_routing[40][40], int PCB_lebar, int PCB_panjang);
void save_program(char PCB_layout [40][40][3], char PCB_routing [40][40], int PCB_lebar, int PCB_panjang, char n[20]);
int validasi_simbol(char simbol);
#endif
