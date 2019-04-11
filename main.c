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
// 3. Audric Christo K Saragih - 13217044 : Perancangan dan penggabungan Main Program
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

int main() {
	int Menu = 0, MenuUtama = 0;
	char layout[40][40][3], routing[40][40];
	char namaProyek[20];
	int brs, klm;
	component_t komponen;
	//char PCB_layout[40][40][3];
	//char PCB_routing[40][40];

	Menu = askMenu();

	while((Menu < 1) || (Menu > 3)) {
		printf("Menu tidak valid. Masukan : ");
		scanf("%d", &Menu);
	}

	while(Menu == 3) {
		break;
	}

	if(Menu == 1) {
		printf("====== Membuat Proyek Baru ======\n");
		printf("Masukkan nama proyek : ");
		scanf("%s", namaProyek);
		printf("Masukkan ukuran PCB NxM (N,M < 40) : ");
		scanf("%d %d", &brs, &klm);

		//inisialisasi array layout kosong
		for(int i = 0; i < 40; i++) {
			for(int j = 0; j < 40; j++) {
					strcpy(layout[i][j], " ");
			}
		}

		//inisialisasi array routing kosong
		for(int i = 0; i < brs; i++) {
			for(int j = 0; j < klm; j++) {
				routing[i][j] = ' ';
			}
		}
		
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
        scanf("%d", &MenuUtama);
			
        while(MenuUtama != 99){
            if(MenuUtama==1)
                printMatrix(layout,brs,klm);
            else if(MenuUtama==2)
                interfaceLayout(&komponen, layout, brs, klm);
            else if (MenuUtama==3)
                tampilkanRouting(routing, brs, klm);
            else if (MenuUtama==4)
                routingManual(routing,klm,brs);
			else if (MenuUtama==8){
                save_program(layout,klm,brs);
                Menu = askMenu();
			}
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
            scanf("%d", &MenuUtama);
        }
	}

	else if(Menu == 2) {
        load(layout,routing);
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
        scanf("%d", &MenuUtama);
        while(MenuUtama != 99){
            if(MenuUtama==1)
                printMatrix(layout,brs,klm);
            else if(MenuUtama==2)
                interfaceLayout(&komponen, layout, brs, klm);
            else if (MenuUtama==3)
                tampilkanRouting(routing, brs, klm);
            else if (MenuUtama==4)
                routingManual(routing,klm,brs);
			else if (MenuUtama==8){
                    save_program(layout,klm,brs);
                    Menu = askMenu();
			}
			
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
            scanf("%d", &MenuUtama);
        }

	}

	return 0;
}
