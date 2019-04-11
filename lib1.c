//***********************************************************//
// [ Source Code ] //
// Institution : Institut Teknologi Bandung
// Name : Patrick Ryan Wijaya
// File Name : lib1.c
// Dependency : lib1.h
// Description:
// Source Code library untuk layouting manual dan tampilan
// hasil layouting Manual
// // Status:
// 1. Patrick Ryan Wijaya - 13217027 : Perancangan source code
//***********************************************************//

#include "lib1.h"
//asumsi kaki komponen hanya bisa disusun secara horizontal dan vertikal, tidak bisa secara diagonal untuk mempermudah perhitungan jarak antar kaki komponen.

void interfaceLayout(component_t *c,char matrix[40][40][6], int baris, int kolom){ //Interface Input dari Layouting manual
    char coma;
    int i,j;
    printf("Isi 'q' atau 'Q' untuk kembali ke menu \n");
      while(((*c).name[0] != 'Q') && ((*c).name[0] != 'q')) //Kondisi terminasi saat input Q atau q
      {
    printf("Pilih Komponen (R,C,T,J): ");
    scanf("%s",(*c).name);
        if((*c).name[0]== 'R'){ //Saat dipilih komponen resistor
            printf("Koordinat kaki 1: ");
            scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
            printf("Koordinat kaki 2: ");
            scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
            while((((*c).koor1.x>baris) || ((*c).koor1.y>kolom) || ((*c).koor2.x>baris) || ((*c).koor2.y>kolom)) //validasi awal input pengguna
                  || (((*c).koor1.x != (*c).koor2.x) && ((*c).koor1.y != (*c).koor2.y)) || (((*c).koor1.x == (*c).koor2.x) && ((*c).koor1.y == (*c).koor2.y)))
            {
                printf("Input komponen pada PCB tidak valid!\n");
                printf("Koordinat kaki 1: ");
                scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
                printf("Koordinat kaki 2: ");
                scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
            }
             while(((*c).koor1.x == (*c).koor2.x) && (abs((*c).koor1.y-(*c).koor2.y)<4)) //Validasi dengan kondisi tertentu
            {
                printf("Jarak Horizontal komponen tidak sesuai!\n");
                printf("Koordinat kaki 1: ");
                scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
                printf("Koordinat kaki 2: ");
                scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
            }
             while(((*c).koor1.y == (*c).koor2.y) && (abs((*c).koor1.x-(*c).koor2.x)<4))
            {
                printf("Jarak vertikal komponen tidak sesuai!\n");
                printf("Koordinat kaki 1: ");
                scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
                printf("Koordinat kaki 2: ");
                scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
            }
            while((matrix[(*c).koor1.x][(*c).koor1.y][1]!= '\0') || (matrix[(*c).koor2.x][(*c).koor2.y][1] != '\0') ) //Pengecekan koordinar sudah diisi atau belum
            {
                printf("SUDAH TERISI!\n");
                printf("Koordinat kaki 1: ");
                scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
                printf("Koordinat kaki 2: ");
                scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
            }
            strcpy(matrix[(*c).koor1.x][(*c).koor1.y],(*c).name);
            strcpy(matrix[(*c).koor2.x][(*c).koor2.y],(*c).name);
        }
        else if((*c).name[0]== 'C'){ //Dipilih komponen kapasitor
            printf("Koordinat kaki 1: ");
            scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
            printf("Koordinat kaki 2: ");
            scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
            while((((*c).koor1.x>baris) || ((*c).koor1.y>kolom) || ((*c).koor2.x>baris) || ((*c).koor2.y>kolom)) //Validasi awal input pengguna
                  || (((*c).koor1.x != (*c).koor2.x) && ((*c).koor1.y != (*c).koor2.y)) || (((*c).koor1.x == (*c).koor2.x) && ((*c).koor1.y == (*c).koor2.y)))
            {
                printf("Input komponen pada PCB tidak valid!\n");
                printf("Koordinat kaki 1: ");
                scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
                printf("Koordinat kaki 2: ");
                scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
            }
             while(((*c).koor1.x == (*c).koor2.x) && (abs((*c).koor1.y-(*c).koor2.y)<2)) //Validasi dengan kondisi tertentu
            {
                printf("Jarak Horizontal komponen tidak sesuai!\n");
                printf("Koordinat kaki 1: ");
                scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
                printf("Koordinat kaki 2: ");
                scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
            }
             while(((*c).koor1.y == (*c).koor2.y) && (abs((*c).koor1.x-(*c).koor2.x)<2))
            {
                printf("Jarak vertikal komponen tidak sesuai!\n");
                printf("Koordinat kaki 1: ");
                scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
                printf("Koordinat kaki 2: ");
                scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
            }
            while((matrix[(*c).koor1.x][(*c).koor1.y][1]!= '\0') || (matrix[(*c).koor2.x][(*c).koor2.y][1]!= '\0') ) //Pengecekan apakah posisi sudah diisi atau belum
            {
                printf("SUDAH TERISI!\n");
                printf("Koordinat kaki 1: ");
                scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
                printf("Koordinat kaki 2: ");
                scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
            }
            strcpy(matrix[(*c).koor1.x][(*c).koor1.y],(*c).name);
            strcpy(matrix[(*c).koor2.x][(*c).koor2.y],(*c).name);
        }
        else if((*c).name[0]== 'J'){ //Jika dipilih Komponen Jumper
            printf("Koordinat kaki 1: ");
            scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
            printf("Koordinat kaki 2: ");
            scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
            while((((*c).koor1.x>baris) || ((*c).koor1.y>kolom) || ((*c).koor2.x>baris) || ((*c).koor2.y>kolom)) //Validasi awal input pengguna
                  || (((*c).koor1.x != (*c).koor2.x) && ((*c).koor1.y != (*c).koor2.y)) || (((*c).koor1.x == (*c).koor2.x) && ((*c).koor1.y == (*c).koor2.y)))
            {
                printf("Input komponen pada PCB tidak valid!\n");
                printf("Koordinat kaki 1: ");
                scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
                printf("Koordinat kaki 2: ");
                scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
            }
             while(((*c).koor1.x == (*c).koor2.x) && (abs((*c).koor1.y-(*c).koor2.y)<1)) //Validasi dengan kondisi tertentu
            {
                printf("Jarak Horizontal komponen tidak sesuai!\n");
                printf("Koordinat kaki 1: ");
                scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
                printf("Koordinat kaki 2: ");
                scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
            }
             while(((*c).koor1.y == (*c).koor2.y) && (abs((*c).koor1.x-(*c).koor2.x)<1))
            {
                printf("Jarak vertikal komponen tidak sesuai!\n");
                printf("Koordinat kaki 1: ");
                scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
                printf("Koordinat kaki 2: ");
                scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
            }
            while((matrix[(*c).koor1.x][(*c).koor1.y][1]!= '\0') || (matrix[(*c).koor2.x][(*c).koor2.y][1]!= '\0') ) //Mengecek apakah koordinat sudah terisi sebelumnya
            {
                printf("SUDAH TERISI!\n");
                printf("Koordinat kaki 1: ");
                scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
                printf("Koordinat kaki 2: ");
                scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
            }
            strcpy(matrix[(*c).koor1.x][(*c).koor1.y],(*c).name);
            strcpy(matrix[(*c).koor2.x][(*c).koor2.y],(*c).name);
        }
        else if((*c).name[0]== 'T'){ //Jika dipilih komponen BJT
            printf("Koordinat kaki 1: ");
            scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
            printf("Koordinat kaki 2: ");
            scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
            printf("Koordinat kaki 3: ");
            scanf("%d%c%d",&(*c).koor3.x,&coma,&(*c).koor3.y);
            while(
                  (((*c).koor1.x>baris) || ((*c).koor1.y>kolom) || ((*c).koor2.x>baris) || ((*c).koor2.y>kolom) || ((*c).koor3.x>baris) || ((*c).koor3.y>kolom))
                  || (((*c).koor1.x != (*c).koor2.x) && ((*c).koor1.y != (*c).koor2.y) && ((*c).koor1.x != (*c).koor3.x) && ((*c).koor1.y != (*c).koor3.y) && ((*c).koor2.x != (*c).koor3.x) && ((*c).koor2.y != (*c).koor3.y))
                  || ((((*c).koor1.x == (*c).koor2.x) && ((*c).koor1.y == (*c).koor2.y)) || (((*c).koor1.x == (*c).koor3.x) && ((*c).koor1.y == (*c).koor3.y)) || (((*c).koor2.x == (*c).koor3.x) && ((*c).koor2.y == (*c).koor3.y)))
                  )//Validasi awal input User
            {
                printf("Input komponen pada PCB tidak valid!\n");
                printf("Koordinat kaki 1: ");
                scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
                printf("Koordinat kaki 2: ");
                scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
                printf("Koordinat kaki 3: ");
                scanf("%d%c%d",&(*c).koor3.x,&coma,&(*c).koor3.y);
            }
            while((((*c).koor1.x == (*c).koor2.x) && ((*c).koor1.x == (*c).koor3.x) && ((abs((*c).koor1.y-(*c).koor2.y)<2)||(abs((*c).koor2.y-(*c).koor3.y)<2)))) //Pengecekan input user pada kondisi tertentu
            {
                printf("Jarak Horizontal komponen tidak sesuai!\n");
                printf("Koordinat kaki 1: ");
                scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
                printf("Koordinat kaki 2: ");
                scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
                printf("Koordinat kaki 3: ");
                scanf("%d%c%d",&(*c).koor3.x,&coma,&(*c).koor3.y);
            }
            while((((*c).koor1.x == (*c).koor2.x) && ((*c).koor2.y == (*c).koor3.y) && ((abs((*c).koor1.y-(*c).koor2.y)<2)||(abs((*c).koor2.x-(*c).koor3.x)<2))))
            {
                printf("Jarak komponen tidak sesuai!\n");
                printf("Koordinat kaki 1: ");
                scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
                printf("Koordinat kaki 2: ");
                scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
                printf("Koordinat kaki 3: ");
                scanf("%d%c%d",&(*c).koor3.x,&coma,&(*c).koor3.y);
            }
            while((((*c).koor1.y == (*c).koor2.y) && ((*c).koor1.y == (*c).koor3.y) && ((abs((*c).koor1.x-(*c).koor2.x)<2)||(abs((*c).koor2.x-(*c).koor3.x)<2))))
            {
                printf("Jarak vertikal komponen tidak sesuai!\n");
                printf("Koordinat kaki 1: ");
                scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
                printf("Koordinat kaki 2: ");
                scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
                printf("Koordinat kaki 3: ");
                scanf("%d%c%d",&(*c).koor3.x,&coma,&(*c).koor3.y);
            }
            while((((*c).koor1.y == (*c).koor2.y) && ((*c).koor2.x == (*c).koor3.x) && ((abs((*c).koor1.x-(*c).koor2.x)<2)||(abs((*c).koor2.y-(*c).koor3.y)<2))))
            {
                printf("Jarak antar komponen tidak sesuai!\n");
                printf("Koordinat kaki 1: ");
                scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
                printf("Koordinat kaki 2: ");
                scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
                printf("Koordinat kaki 3: ");
                scanf("%d%c%d",&(*c).koor3.x,&coma,&(*c).koor3.y);
            }
            while((matrix[(*c).koor1.x][(*c).koor1.y][1]!= '\0') || (matrix[(*c).koor2.x][(*c).koor2.y][1] != '\0') || (matrix[(*c).koor3.x][(*c).koor3.y][1] != '\0') ) //Pengecekan apakah Koordinat
                                                                                                                                                                        //sudah terisi
            {
                printf("SUDAH TERISI!\n");
                printf("Koordinat kaki 1: ");
                scanf("%d%c%d",&(*c).koor1.x,&coma,&(*c).koor1.y);
                printf("Koordinat kaki 2: ");
                scanf("%d%c%d",&(*c).koor2.x,&coma,&(*c).koor2.y);
                printf("Koordinat kaki 3: ");
                scanf("%d%c%d",&(*c).koor3.x,&coma,&(*c).koor3.y);
            }
            strcpy(matrix[(*c).koor1.x][(*c).koor1.y],(*c).name); //Memasukkan Komponen tervalidasi ke Array 3 Dimensi
            strcpy(matrix[(*c).koor2.x][(*c).koor2.y],(*c).name);
            strcpy(matrix[(*c).koor3.x][(*c).koor3.y],(*c).name);
        }
}
}
void printMatrix(char matr[40][40][6], int row, int col){ //Prosedur Menampilkan Array hasil Layouting Manual
       int i,j,k;
    for(k = 0; k<= col; k++) {
		printf("%d\t", k);
	}
	printf("\n");
    for (i=1;i<=row;i++){
            printf("%d\t", i);
    for (j=1;j<=col;j++){

        printf("%s\t",matr[i][j]);
    }
    printf("\n");
}
printf("\n");
}



