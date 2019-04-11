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

void load(char PCB_layout[40][40][6], char PCB_routing[40][40],int PCB_lebar,int PCB_panjang){
	FILE *file1;
	FILE *file2;
	int i,j,k,lebar;
	char baca_layout[40][100];
	char baca_routing[40][100];
	char nama_file[50];
	int index_arr, idx, baris, kolom;

	printf("Masukkan nama file PCB layout yang akan dibaca: ");
	scanf(" %[^\n]s",nama_file);
	strcat(nama_file,".csv");
	file1 = fopen(nama_file,"r");

	//check if the file pointer is null
	lebar=0;
	if (file1 == NULL){
		printf("File tidak dapat dibuka");
	}

	else {
		while(fgets(baca_layout[lebar],50,file1) != NULL){
			lebar = lebar+1;
		}
	}
	fclose(file1);
	for(i=0;i<40;i++){
		for(j=0;j<40;j++){
			strcpy(PCB_layout[i][j]," ");
		}
	}

		i=0;  baris=0; index_arr =0;
	while(i<lebar){
		kolom =0;idx=0;
		while(baca_layout[i][idx]!='\n'){
			if(baca_layout[i][idx]==' '){
				PCB_layout[baris][kolom][index_arr]=' ';
			//printf("(%d,%d,%d) %c\n", baris,kolom,index_arr,PCB_layout[baris][kolom][index_arr]);
			}
			else if(baca_layout[i][idx]!=',' ){
				PCB_layout[baris][kolom][index_arr]=baca_layout[i][idx];
				//printf("\n%s\n", PCB_layout[0][2]);
				//printf("(%d,%d,%d) %c\n", baris,kolom,index_arr,PCB_layout[baris][kolom][index_arr]);
				index_arr++;
			}
			else if(baca_layout[i][idx]==','){
				//printf("\n%s\n", PCB_layout[0][2]);
				index_arr=0;
				kolom++;
			}
			//printf("\n%s\n", PCB_layout[0][2]);
			idx++;
		}
		//printf("\n%s\n", PCB_layout[0][2]);
		baris++;
		i++;
	}
	PCB_lebar = lebar;
	PCB_panjang = kolom;
	//ngeprint
	   for(k = 0; k<kolom; k++) {
		printf("%d\t", k);
	}
	printf("\n");
	for(i=1;i<baris;i++){
            printf("%d\t", i);
		for(j=0;j<=kolom;j++){
			printf("%s\t",PCB_layout[i][j+1]);
		}
		printf("\n");
	}
		printf("\n");
	// load PCB_routing
	lebar=0;
	printf("Masukkan nama file PCB routing yang akan dibaca: ");
	scanf(" %[^\n]s",nama_file);
	strcat(nama_file,".csv");
	file2 = fopen(nama_file,"r");
	if (file2 == NULL){
		printf("File tidak dapat dibuka");
	}

	else {
		while(fgets(baca_routing[lebar],50,file2) != NULL){
			lebar = lebar+1;
		}
	}
	printf("%d\n",lebar);
	fclose(file2);
	for(i=0;i<40;i++){
		for(j=0;j<40;j++){
			PCB_routing[i][j]=' ';
		}
	}
	lebar = PCB_lebar;
	kolom = PCB_panjang;
	i=0;  baris =0;
	//ngeload
	while(i<lebar){
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
	//ngeprint
	for(k = 0; k< kolom; k++) {
		printf("%d\t", k);
	}
		printf("\n");
	for(i=1;i<baris;i++){
        printf("%d\t", i);
		for(j=0;j<=kolom;j++){
			printf("%c\t",PCB_routing[i][j+1]);
		}
		printf("\n");
	}
		printf("\n");
}
