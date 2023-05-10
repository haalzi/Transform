#include "hederTree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	//KAMUS DATA
	addressNBT root = NULL;
	addressBT Newroot = NULL;
	infotype X;
	int jmlnode;
	int choice;
	char teb[] = " ";
	char ulang;

	//PROGRAM

	do{
		Tampil_menu();
		printf("\nPilih : ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("Masukkan jumlah node :");
				scanf("%d", &jmlnode);
				Create_tree(&root, jmlnode);
			break;

			case 2:
				loading();
				Preorder(root, &Newroot);
//				Newroot = convert(Newroot, root->info);
//				Print_TreeBT(Newroot, teb);
			break;

			case 3:
//				PreorderNBT(root);
				printf("\n");
				Print_TreeNBT(root, teb);
				printf("\n");
//				PreorderBT(Newroot);
				inOrder(Newroot);
//				Print_TreeBT(Newroot, teb);
			break;

			case 4:
			break;

		}

	printf("\nApakah ingin kembali ke menu?");
	ulang = getch();
	system("cls");
	}while(ulang == 'y');

}
