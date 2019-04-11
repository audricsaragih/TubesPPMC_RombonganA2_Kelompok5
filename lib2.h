#ifndef LIB2_H
#define LIB2_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct titik{
	int x;
	int y;
}koordinat[50];

void routingManual(char PCB_routing[40][40], int PCB_lebar, int PCB_panjang);
void save_program(char PCB_layout [40][40][2],int PCB_lebar, int PCB_panjang);
int validasi_simbol(char simbol);
#endif
