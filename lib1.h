#ifndef LIB1_H
#define LIB1_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int x,y;
}koordinat_t;

typedef struct{
    char name[2];
    koordinat_t koor1, koor2, koor3;
}component_t;

void interfaceLayout(component_t *c,char matrix[40][40][3],int baris, int kolom);
void printMatrix(char matr[40][40][3], int row, int col);
#endif

