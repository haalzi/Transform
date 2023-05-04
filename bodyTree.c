#include "hederTree.h"

address Alokasi(infotype X) {
	address Pnew = (address)malloc(sizeof(AVL));
	if (Pnew != nil) {
		Pnew->info = X;
		Pnew->LS = nil;
		Pnew->RS = nil;
		Pnew->PR = nil;
		Pnew->tinggi = 0;
	}
	return Pnew;
}

void Create_tree(address *root, int Jml_Node) {

	address child, parent, Pnew = *root;
	infotype X;
	char c;

	int posisi = 1, Jml_son = 1, jum_enty = 1;
	//address parent;
	parent = NULL;

//	*root = NULL;
	if (Jml_Node > 0) {
		if (*root == NULL) {
			printf("\nMasukkan nilai untuk Root: ");
			scanf(" %c", &X);
			*root = Alokasi(X);
			fflush(stdin);
			jum_enty++;
		}

		parent = *root;

		while (jum_enty <= Jml_Node) {
			printf("\nNilai Parent: %c", parent->info);
			printf("\nJumlah Anak: ");
			scanf("%d", &Jml_son);
			fflush(stdin);

			if ((Jml_son > 0) && (posisi + Jml_son <= Jml_Node)) {
				int i;
				//address child;
				child = NULL;
				address childSebelum;
				childSebelum = NULL;
				for (i = 1; i <= Jml_son; i++) {
					posisi = posisi + 1;
					printf("Anak ke %d: ", i);
					scanf(" %c", &X);
					child = Alokasi(X);
					fflush(stdin);
					jum_enty++;

					if (i == 1) {
						parent->FS = child;
						childSebelum = child;
					} else if (i < Jml_son) {
						childSebelum->NB = child;
						childSebelum = child;
					} else {
						childSebelum->NB = child;
						child->RS = NULL;
					}
					child->PR = parent;
				}
				if((parent->RS) == NULL) {
					parent =(parent->LS);
				} else {
					parent = parent->RS;
				}

			} else if (Jml_son == 0) {
				parent = parent->RS;
			} else if (posisi+Jml_son > Jml_Node) {
				printf("\n\nOVERFLOW melebihi alokasi yang sudah ada");
				parent = parent;
			}
		}
	}
}

void Print_Tree(address root, char tab[]) {
	char tempTab[255];
	strcpy(tempTab, tab);
	strcat(tempTab, "-");

	if (root!=NULL) {
		printf("%s%c\n", tab,root->info);
		Print_Tree(root->LS, tempTab);
		Print_Tree(root->RS, tab);
	}
}

void Tampil_menu() {
	printf("\nPilih menu : ");
	printf("\n1. Create Tree");
	printf("\n2. Convert Tree");
	printf("\n3. Print Tree");
	printf("\n4. Change Theme\n");
}