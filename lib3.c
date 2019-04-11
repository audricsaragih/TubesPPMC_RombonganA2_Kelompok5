#include "lib3.h"

void tampilkanRouting(char routing[40][40], int brs, int klm) {
	int i, j;

	for(int l = 0; l <= klm; l++) {
		printf("%d\t", l);
	}
	printf("\n");

	for(i = 0; i < brs; i++) {
		printf("%d\t", i+1);
		for(j = 0; j < klm; j++) {
			printf("%c", routing[brs][klm]);
		}
		printf ("\n");
	}
	printf ("\n");
}

int loadProject(char proyekLayout[30], char proyekRouting[30]) {
	char layout[40][40][2];
	char routing[40][40][2];
	char lay, rou;
	int exist = 1;

	// load layout file
	FILE *fp;
	fp = fopen ("filter_RC_sederhana_layout.csv", "r");

	for(int i = 0; i < 40; i++) {
		for(int j = 0; j < 100; i++) {
			for(int k = 0; k < 2; k++) {
				fscanf(fp, "%c", &lay);
				if(lay == ',') {
					k = 2;
				}
				else if(lay == '\n') {
					k = 2;
					j = 100;
				}
				else {
					layout[i][j][k] = lay;
				}
			}
		}
	}

	// load routing file
	FILE *fp2;
	fp2 = fopen ("filter_RC_sederhana_routing.csv", "r");

	for(int i = 0; i < 40; i++) {
		for(int j = 0; j < 100; i++) {
			for(int k = 0; k < 2; k++) {
				fscanf(fp2, "%c", &rou);
				if(rou == ',') {
					k = 2;
				}
				else if(rou == '\n') {
					k = 2;
					j = 100;
				}
				else {
					routing[i][j][k] = rou;
				}
			}
		}
	}
	return exist;
}
