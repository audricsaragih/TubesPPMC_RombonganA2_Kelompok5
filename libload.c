#include "libload.h"

void loadProject(char l[40][40][2], char r[40][40], char nama[20]) {
	char lay, rou;
	char namatemp[20];
	
	strcpy(namatemp, nama);
	
	printf("Nama proyek : ");
	scanf("%s", namatemp);
	
	// load file layout
	strcat(namatemp, "_layout.csv");
	
	FILE *fp1;
	fp1 = fopen(nama, "r");
	
	for(int i = 0; i < 40; i++) {
		for(int j = 0; j < 40; j++) {
			for(int k = 0; k < 2; k++) {
				fscanf(fp1, "%c", &lay);
				if (lay != ';') {
						l[i][j][k] = lay;
				}
			}
		}
	}
	
	// load file routing
	strcat(nama, "_routing.csv");
	
	FILE *fp2;
	fp2 = fopen(nama, "r");
	
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
}
