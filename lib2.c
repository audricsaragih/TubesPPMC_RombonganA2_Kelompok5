//***********************************************************//
// [ Source Code ] //
// Institution : Institut Teknologi Bandung
// Name : Hillary Christine R
// File Name : lib2.c
// Dependency : lib2.h
// Description:
// Source Code library untuk Routing Manual dan Menyimpan
// Program.
// // Status:
// 1. Hillary Christine R - 13217030 : Perancangan Source Code
//***********************************************************//

#include "lib2.h"

void routingManual(char PCB_routing[40][40], int PCB_lebar, int PCB_panjang){
	int i,j,N,n,idx_size,route_nabrak,baris,kolom;
	char point[10];
	char temp;
	char arr[10][10];
	int valid;
	titik koordinat[50];
	//int validasi_koordinat (int x1,int x2, int y1,int y2);
	//int validasi_routing(char PCB_routing[40][40],int x1, int x2, int y1, int y2);
	char simbol;
	//inisiasi dulu semua matriks isinya spasi

	printf("Pilih simbol (!,@,#,$,%,^,&,*,(,)) : ");
	scanf("%c",&temp);
	scanf("%c",&simbol);

	valid=validasi_simbol(simbol);

	while(valid == 0){
		printf("Simbol yang dipilih tidak tepat, input kembali simbol!\n ");
		printf("Pilih simbol (!,@,#,$,%,^,&,*,(,)) : ");
		scanf("%c",&simbol);
		scanf("%c",&temp);
		valid=validasi_simbol(simbol);
	}

	for(i=0;i<=PCB_panjang;i++){
		for(j=0;j<=PCB_lebar;j++){
			PCB_routing[i][j]= ' ';
		}
	}
	i=0;
	while(strcmp(arr[i-1],"Q")||strcmp(arr[i-1],"q")){
		printf("Koordinat y,x : ");
		scanf("%s",&point);
		scanf("%c",&temp);
		strcpy(arr[i],point);
		// ngecek kalo udah diubah variabelnya dari point ke integer
		// ketika pengguna memasukkan input koordinat n, maka akan memulai noda baru dengan membuat i = 0
		if (!strcmp(point,"N") || !strcmp(point,"n")){
			printf("Memulai noda baru \n");
			printf("Pilih simbol (!,@,#,$,%,^,&,*,(,)) : ");
			scanf("%c",&simbol);
			valid = validasi_simbol(simbol);
			while(valid == 0){
				printf("Simbol yang dipilih tidak tepat, input kembali simbol : ");
				printf("Pilih simbol (!,@,#,$,%,^,&,*,(,)) : ");
				scanf("%c",simbol);
				valid = validasi_simbol(simbol);
			}
			printf("Koordinat x, y : ");
			i=0;
			scanf("%s",&point);
			scanf("%c",&temp);
			strcpy(arr[i],point);
			N = strlen (arr[i]);
			idx_size = 0;
			while(idx_size<N){
				if( arr[i][idx_size] != ','){
					idx_size = idx_size+1;
				}
				else {
					arr[i][idx_size]= ' ';
				}
			}
			sscanf(arr[i], "%d %d", &koordinat[i].y, &koordinat[i].x);
			printf("koordinat y, x  adalah: %d, %d \n", koordinat[i].y, koordinat[i].x); // ngecek kalo udah diubah variabelnya dari point ke integer
			i=i+1;
			// INPUT KEMBALI KOORDINAT PADA NODA BARU
		}
		else if(strcmp(point,"q")==0 || strcmp(point,"Q")==0) {
			break;
		}
		else {
			N = strlen (arr[i]);
			idx_size = 0;
			while(idx_size<N){
				if( arr[i][idx_size] != ','){
					idx_size = idx_size+1;
				}
				else {
					arr[i][idx_size]= ' ';
				}
			}
			sscanf(arr[i], "%d %d", &koordinat[i].y, &koordinat[i].x);
			printf("koordinat y, x  adalah: %d, %d \n", koordinat[i].y, koordinat[i].x);
			i=i+1;
			// perlu dua titik koordinat yang dinput agar bisa membuat noda
			if (i>1){
				printf("koordinat y, x sebelumnya  adalah: %d, %d \n", koordinat[i-2].y, koordinat[i-2].x);
				printf("koordinat y, x sekarang adalah: %d, %d \n", koordinat[i-1].y, koordinat[i-1].x);
				if (koordinat[i-1].x==koordinat[i-2].x||koordinat[i-1].y==koordinat[i-2].y){
					valid = 1;
				}
				else {
					valid = 0;
				}
				printf("validasi %d\n",valid);
				// validasi apakah koordinat berada di noda yang sama
				while (valid==0){
					if(!strcmp(arr[i-1],"N") || !strcmp(arr[i-1],"n")){ // ketika inputan n ia akan ke noda baru
						valid = 1;
					}
					else if (!strcmp(arr[i-1],"Q") || !strcmp(arr[i-1],"q")){ // ketika inputan n ia akan ke noda baru
						valid =1;
					}
					else {
						printf("titik koordinat yang dipilih berada di noda berbeda, input kembali koordinat :\n");
						printf("Koordinat y, x: ");
						scanf("%s",&point);
						strcpy(arr[i-1],point);
						scanf("%c",&temp);
						N = strlen (arr[i-1]);
						idx_size = 0;
						while(idx_size<N){
							if( arr[i-1][idx_size] != ','){
								idx_size = idx_size+1;
							}
							else {
								arr[i-1][idx_size]= ' ';
							}
						}
						sscanf(arr[i-1], "%d %d", &koordinat[i-1].y, &koordinat[i-1].x);
						printf("koordinat y, x sebelumnya  adalah: %d, %d \n", koordinat[i-2].y, koordinat[i-2].x);
						printf("koordinat y, x sekarang adalah: %d, %d \n", koordinat[i-1].y, koordinat[i-1].x);
						if (koordinat[i-1].x==koordinat[i-2].x || koordinat[i-1].y==koordinat[i-2].y){
							valid = 1;
						}
						else {
							valid = 0;
						}
					}
				}
				// buat matriksnya
				if(koordinat[i-2].y<koordinat[i-1].y){
					for(kolom=koordinat[i-2].y ; kolom<=koordinat[i-1].y; kolom++){
						if(koordinat[i-2].x<koordinat[i-1].x){
							for(baris=koordinat[i-2].x ; baris<=koordinat[i-1].x; baris++){
								PCB_routing[kolom][baris]= simbol;
							}
						}
						else{
							for(baris=koordinat[i-1].x ; baris<=koordinat[i-2].x; baris++){
								PCB_routing[kolom][baris]= simbol;
							}
						}
					}
				}

				else{
					for(kolom=koordinat[i-1].y ; kolom<=koordinat[i-2].y; kolom++){
						if(koordinat[i-2].x<koordinat[i-1].x){
							for(baris=koordinat[i-2].x ; baris<=koordinat[i-1].x; baris++){
								PCB_routing[kolom][baris]= simbol;
							}
						}
						else{
							for(baris=koordinat[i-1].x ; baris<=koordinat[i-2].x; baris++){
								PCB_routing[kolom][baris]= simbol;
							}
						}
					}

				}

				for(kolom=0;kolom<=PCB_panjang;kolom++){
					printf("%d", kolom);
					for(baris=0;baris<=PCB_lebar;baris++){
						if(kolom == 0 && baris == 0){
							printf("\t");
						}
						else{
							if(kolom==0){
								printf("%d\t", baris);
							}
							else {
								printf("%c\t",PCB_routing[kolom][baris]);
							}
						}
					}
					printf("\n");
				}
			}
		}

	}
	printf("menu baru\n");

}

void save_program(char PCB_layout [40][40][6],char PCB_routing[40][40]  ,int PCB_lebar, int PCB_panjang){
	char nama[100], namaL[100], namaR[100];
	int i,j;

	printf("Masukkan nama File untuk disimpan: ");
	scanf("%s",&nama);
	strcpy(namaL,nama);
	strcpy(namaR,nama);
	strcat(namaL,"_layout.csv");
	strcat(namaR,"_routing.csv");

	FILE *fin=fopen(namaL,"w");

	for (i=0;i<=PCB_panjang;i++){
		for(j=0;j<=PCB_lebar;j++){
			fprintf(fin,"%s,",PCB_layout[i][j]);
		}
		fprintf(fin,"\n");
	}
	fclose(fin);

	FILE *finn=fopen(namaR,"w");
	for(i=0;i<=PCB_panjang;i++){
		for(j=0;j<=PCB_lebar;j++){
			fprintf(finn," %c,",PCB_routing[i][j]);
		}
		fprintf(finn,"\n");
	}
	fclose(finn);
}
int validasi_simbol(char simbol){
	if (simbol =='!'||simbol =='@'||simbol =='#'||simbol =='$'||simbol =='%'||simbol =='^'||simbol =='&'||simbol =='*'||simbol =='('||simbol ==')'){
		return 1;
	}
	else {
		return 0;
	}
}

