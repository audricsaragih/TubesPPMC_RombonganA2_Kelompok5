//***********************************************************//
// [ Source Code ] //
// Institution : Institut Teknologi Bandung
// Name : Patrick Ryan Wijaya , Hillary Christine R, Audric Christo K Saragih
// File Name : main.c
// Dependency : lib1.h, lib2.h, lib3.h
// Description:
// Program merupakan program desain PCB dengan fitur layouting
// dan routing Manual
// // Status:
// 1. Patrick Ryan Wijaya - 13217027 : Debugging Main Program
// 2. Hillary Christine R - 13217030 : Perancangan awal main Program
// 3. Audric Christo K Saragih - 13217044 : Perancangan, debugging dan penggabungan Main Program
//***********************************************************//

#include "lib1.h"
#include "lib2.h"
#include "lib3.h"

int askMenu() {
	int menu;

	printf("Menu: \n");
	printf("1. Buat Proyek Baru \n");
	printf("2. Muat Proyek dari Berkas \n");
	printf("3. Keluar \n");
	printf("Masukan: ");
	scanf("%d", &menu);

	return menu;
}

int askMenuUtama() {
	int menuutama;

	printf("[Menu Utama] \n");
	printf("Pilih Mode: \n");
	printf("1. Tampilkan Layout \n");
	printf("2. Layouting Manual \n");
	printf("3. Tampilkan Routing \n");
	printf("4. Routing Manual \n");
	printf("5. Layout Otomatis \n");
	printf("6. Routing Otomatis \n");
	printf("7. Design Rule Checker \n");
	printf("8. Simpan Proyek dan Keluar \n");
	printf("Pilih Mode: ");
	scanf("%d", &menuutama);

	return menuutama;
}

int main() {
	int Menu = 99, MenuUtama = 99;
	char layout[40][40][6], routing[40][40];
	char namaProyek[20];
	int brs, klm;
	component_t komponen;

	do {
		Menu = askMenu();
		while ((Menu < 1) || (Menu > 3)) {
			printf("Menu tidak valid. Masukan : ");
			scanf("%d", &Menu);
		}

		if(Menu == 1) {
			printf("====== Membuat Proyek Baru ======\n");
			printf("Masukkan nama proyek : ");
			scanf("%s", namaProyek);
			printf("Masukkan ukuran PCB NxM (N,M < 40) : ");
			scanf("%d %d", &brs, &klm);
			printf("\n");
            while ((brs < 1) || (brs > 39) || (klm < 1) || (klm > 39)) {
                printf("Ukuran PCB tidak tepat! Ukuran PCB harus diantara 0 dan 40\n");
                printf("Masukkan ukuran PCB NxM (N,M < 40) : ");
                scanf("%d %d", &brs, &klm);
                printf("\n");
            }

			//inisialisasi array layout kosong
			for(int i = 0; i < 40; i++) {
				for(int j = 0; j < 40; j++) {
						strcpy(layout[i][j], " ");
				}
			}

			//inisialisasi array routing kosong
			for(int i = 0; i < 40; i++) {
				for(int j = 0; j < 40; j++) {
					routing[i][j] = ' ';
				}
			}

			MenuUtama = askMenuUtama();
			while ((MenuUtama < 1) || (MenuUtama > 8)) {
				printf("Menu tidak valid. Masukan : ");
				scanf("%d", &MenuUtama);
			}

			while(MenuUtama != 8){
				if(MenuUtama==1) {
					printMatrix(layout,brs,klm);
					MenuUtama = askMenuUtama();
				}
				else if(MenuUtama==2) {
					interfaceLayout(&komponen, layout, brs, klm);
					MenuUtama = askMenuUtama();
				}
				else if (MenuUtama==3) {
					tampilkanRouting(routing, brs, klm);
					MenuUtama = askMenuUtama();
				}
				else if (MenuUtama==4) {
					routingManual(routing,klm,brs);
					MenuUtama = askMenuUtama();
				}
                else if (MenuUtama==5) {
					loadLayout(routing,brs,klm);
					MenuUtama = askMenuUtama();
				}
				else if (MenuUtama==6) {
					printf("---Menu Routing Otomatis saat ini tidak tersedia---\n");
					MenuUtama = askMenuUtama();
				}
				else if (MenuUtama==7) {
					printf("---Menu Design Rule Checker saat ini tidak tersedia---\n");
					MenuUtama = askMenuUtama();
				}
			}
			save_program(layout,routing,klm,brs,namaProyek);
		}

		else if(Menu == 2) {
			load(layout, routing, brs, klm);

			MenuUtama = askMenuUtama();
			while ((MenuUtama < 1) || (MenuUtama > 8)) {
				printf("Menu tidak valid. Masukan : ");
				scanf("%d", &MenuUtama);
			}

			while(MenuUtama != 8){
				if(MenuUtama==1) {
					printMatrix(layout,brs,klm);
					MenuUtama = askMenuUtama();
				}
				else if(MenuUtama==2) {
					interfaceLayout(&komponen, layout, brs, klm);
					MenuUtama = askMenuUtama();
				}
				else if (MenuUtama==3) {
					tampilkanRouting(routing, brs, klm);
					MenuUtama = askMenuUtama();
				}
				else if (MenuUtama==4) {
					routingManual(routing,klm,brs);
					MenuUtama = askMenuUtama();
				}
				else if (MenuUtama==5) {
					loadLayout(routing,brs,klm);
					MenuUtama = askMenuUtama();
				}
				else if (MenuUtama==6) {
					printf("---Menu routing otomatis ini tidak tersedia---\n");
					MenuUtama = askMenuUtama();
				}
				else if (MenuUtama==7) {
					printf("---Menu Deisgn Rule Checker ini tidak tersedia---\n");
					MenuUtama = askMenuUtama();
				}
			}
			save_program(layout,routing,klm,brs,namaProyek);
		}
	} while(Menu != 3);

	return 0;
}

