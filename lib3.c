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

void load(char PCB_layout[40][40][3], char PCB_routing[40][40]){
	FILE *file1;
	FILE *file2;
	int i,j;
	char baca_layout[40][100];
	char baca_routing[40][100];
	char nama_file[50];
	int PCB_lebar;
	int index_arr, idx, baris, kolom;
	
	printf("Masukkan nama file PCB layout yang akan dibaca: ");
	scanf(" %[^\n]s",nama_file);
	strcat(nama_file,".csv");
	file1 = fopen(nama_file,"r");
	
	//check if the file pointer is null
	PCB_lebar=0;
	if (file1 == NULL){
		printf("File tidak dapat dibuka");
	}
	
	else {
		while(fgets(baca_layout[PCB_lebar],50,file1) != NULL){
			printf("%s",baca_layout[PCB_lebar]);
			PCB_lebar = PCB_lebar+1;
		}
	}
	fclose(file1);
	
	for(i=0;i<40;i++){
		for(j=0;j<40;j++){
			strcpy(PCB_layout[i][j]," ");
		}
	}
		i=0;  baris =0; 
	
	while(i<PCB_lebar){
		kolom =0;idx=0;
		while(baca_layout[i][idx]!='\n'){

			if(baca_layout[i][idx]=='\0'){
				PCB_layout[baris][kolom][index_arr]=' ';
			}
			else if(baca_layout[i][idx]!=',' ){
				PCB_layout[baris][kolom][index_arr]=baca_layout[i][idx];
				index_arr++;
			}
			else if(baca_layout[i][idx]==','){
				index_arr=0;
				kolom++;
			}
			printf("ini idx : %d\n",idx);
			idx++;
		}
		baris++;
		i++;
	}
	
	// save PCB_routing
	PCB_lebar=0;
	printf("Masukkan nama file PCB routing yang akan dibaca: ");
	scanf(" %[^\n]s",nama_file);
	strcat(nama_file,".csv");
	file2 = fopen(nama_file,"r");
	if (file2 == NULL){
		printf("File tidak dapat dibuka");
	}
	
	else {
		while(fgets(baca_routing[PCB_lebar],50,file2) != NULL){
			printf("%s",baca_routing[PCB_lebar]);
			PCB_lebar = PCB_lebar+1;
		}
	}
	printf("%d\n",PCB_lebar);
	fclose(file2);
	for(i=0;i<40;i++){
		for(j=0;j<40;j++){
			PCB_routing[i][j]=' ';
		}
	}
	i=0;  baris =0; 
	while(i<PCB_lebar){
		kolom =0;idx=0;
		while(baca_routing[i][idx]!='\n'){

			if(baca_routing[i][idx]=='\0'){
				PCB_routing[baris][kolom]=' ';
			}
			else if(baca_routing[i][idx]!=',' ){
				PCB_routing[baris][kolom]=baca_routing[i][idx];
				index_arr++;
			}
			else if(baca_routing[i][idx]==','){
				kolom++;
			}
			idx++;
		}
		baris++;
		i++;
	}
}

