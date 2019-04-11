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
	char layout[40][40][2], routing[40][40];
	char namaProyek[20], proyekLayout[30], proyekRouting[30];
	int brs, klm;
	component_t komponen;

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
        while(MenuUtama != 99){

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
            switch(MenuUtama){
                case 1 :
                    printMatrix(layout,brs,klm);
                    break;
                case 2 :
                    interfaceLayout(&komponen, layout, brs, klm);
                    break;

                case 3 :
                    tampilkanRouting(routing, brs, klm);
                    break;
                case 4 :
                    routingManual(routing, klm, brs);
                    break;
                case 8 :
                    save_program(layout,klm,brs);
                    Menu = askMenu();
            }
        }
	}

	else if(Menu == 2) {
        loadProject(proyekLayout, proyekRouting);
                while(MenuUtama != 99){

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
            switch(MenuUtama){
                case 1 :
                    printMatrix(layout,brs,klm);
                    break;
                case 2 :
                    interfaceLayout(&komponen, layout, brs, klm);
                    break;

                case 3 :
                    tampilkanRouting(routing, brs, klm);
                    break;
                case 4 :
                    routingManual(routing, klm, brs);
                    break;
                case 8 :
                    save_program(layout,klm,brs);
                    Menu = askMenu();
            }
        }

	}

	return 0;
}
