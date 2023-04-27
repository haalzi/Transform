#include "hederTree.h"

address Alokasi(infotype X) {
	address Pnew = (address)malloc(sizeof(address));
	if (Pnew != nil) {
		Pnew->info = X;
		Pnew->LS = nil;
		Pnew->RS = nil;
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

	*root = NULL;
	if (Jml_Node > 0) {
		printf("\nMasukkan nilai untuk Root: ");
		*root = (address)malloc(sizeof(AVL));
		scanf(" %c", &(*root)->info);
		fflush(stdin);
		jum_enty++;

		(*root)->PR = NULL;
		(*root)->LS = NULL;
		(*root)->RS = NULL;

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
					child = (address)malloc(sizeof(AVL));
					scanf(" %c", &(child->info));
					fflush(stdin);
					child->LS = NULL;
					jum_enty++;

					if (i == 1) {
						parent->LS = child;
						childSebelum = child;
					} else if (i < Jml_son) {
						childSebelum->RS = child;
						childSebelum = child;
					} else {
						childSebelum->RS = child;
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

void Print_Tree(address root, char tab[])
{
	char tempTab[255];
	strcpy(tempTab, tab);
	strcat(tempTab, "-");

	if (root!=NULL)
	{
		printf("%s%c\n", tab,root->info);
		Print_Tree(root->LS, tempTab);
		Print_Tree(root->RS, tab);
	}
}

void Tampil_menu()
{
	printf("1. Create Tree\n");
	printf("2. Convert Tree\n");
	printf("3. Print Tree\n");
	printf("4. Change Theme\n");
}

