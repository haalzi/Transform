#include "hederTree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	//KAMUS DATA
	address root;
	int jmlnode;
	int choice;
	char teb[] = " ";
	char ulang = 'y';

	//PROGRAM

	do{

		Tampil_menu();
		printf("\nPilih :");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("Masukkan jumlah node :");
				scanf("%d", &jmlnode);
				Create_tree(&root,jmlnode);
			break;

			case 2:
			break;

			case 3:
				Print_Tree(root, teb);
			break;

			case 4:
			break;

		}

	printf("/nApakah ingin kembali ke menu?");
	ulang = getch();
	}while(ulang == 'y');

}
