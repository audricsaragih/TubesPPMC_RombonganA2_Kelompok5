//***********************************************************//
// [ Source Code ] //
// Institution : Institut Teknologi Bandung
// Name : Audric Christo K Saragih
// File Name : lib3.c
// Dependency : lib3.h
// Description:
// Source Code library untuk tampilan routing, loading project dan loading
// routing file
// // Status:
// 1. Audric Christo K Saragih - 13217044 : Perancangan Source Code
//***********************************************************//
#include "lib3.h"

void tampilkanRouting(char r[40][40], int brs, int klm) {
	int i, j;

	for(int k = 0; k <= klm; k++) {
		printf("%d\t", k);
	}
	printf("\n");

	for(i = 0; i < brs; i++) {
		printf("%d\t", i+1);
		for(j = 0; j < klm; j++) {
			printf("%c", r[brs][klm]);
		}
		printf ("\n");
	}
}

void loadProject(char l[40][40][3], char r[40][40], char nama[20]) {
	char lay, rou;
	char namal[20], namar[20];
	
	printf("\n");
	printf("====== Memuat Proyek Lama ======\n");
	printf("Masukkan nama proyek : ");
	scanf("%s", nama);
	
	strcpy(namal, nama);
	strcpy(namar, nama);
	
	// load file layout
	strcat(namal, "_layout.csv");
	
	FILE *fp1;
	fp1 = fopen(namal, "r");
	
	for(int i = 0; i < 40; i++) {
		for(int j = 0; j < 40; j++) {
			for(int k = 0; k < 3; k++) {
				fscanf(fp1, "%c", &lay);
				if (lay != ';') {
						l[i][j][k] = lay;
				}
			}
		}
	}
	
	printf("File %s telah dimuat\n", namal);
	
	// load file routing
	strcat(namar, "_routing.csv");
	
	FILE *fp2;
	fp2 = fopen(namar, "r");
	
	for(int i = 0; i < 40; i++) {
		int k = 0;
		for(int j = 0; j < 40; j++) {
			fscanf(fp2, "%c", &rou);
			if (rou != ';') {
				k = k + 1;
				if (i == 0) {
					r[i][k-1] = rou;
				}
				else
					r[i][k] = rou;
			}
		}
	}
	printf("File %s telah dimuat\n", namar);
	
}
