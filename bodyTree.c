#include "hederTree.h"

addressNBT AlokasiNBT(infotype X) {
	addressNBT Pnew = (addressNBT)malloc(sizeof(NBT));
	if (Pnew != nil) {
		Pnew->info = X;
		Pnew->FS = nil;
		Pnew->NB = nil;
		Pnew->PR = nil;
	}
	return Pnew;
}

addressBT AlokasiBT(infotype X) {
	addressBT Pnew = (addressBT)malloc(sizeof(AVL));
	if (Pnew != nil) {
		Pnew->info = X;
		Pnew->LS = nil;
		Pnew->RS = nil;
		Pnew->tinggi = 1;
	}
	return Pnew;
}

void Create_tree(addressNBT *root, int Jml_Node) {

	addressNBT child, parent, Pnew = *root;
	infotype X;
	char c;

	int posisi = 1, Jml_son = 1, jum_enty = 1;
	parent = NULL;

	if (Jml_Node > 0) {
		if (*root == NULL) {
			printf("\nMasukkan nilai untuk Root: ");
			scanf(" %c", &X);
			*root = AlokasiNBT(X);
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
				child = NULL;
				addressNBT childSebelum;
				childSebelum = NULL;
				for (i = 1; i <= Jml_son; i++) {
					posisi = posisi + 1;
					printf("Anak ke %d: ", i);
					scanf(" %c", &X);
					child = AlokasiNBT(X);
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
						child->NB = NULL;
					}
					child->PR = parent;
				}
				if((parent->NB) == NULL) {
					parent = parent->FS;
				} else {
					parent = parent->NB;
				}

			} else if (Jml_son == 0) {
				parent = parent->NB;
			} else if (posisi+Jml_son > Jml_Node) {
				printf("\n\nOVERFLOW melebihi alokasi yang sudah ada");
			}
		}
	}
}

addressBT rightRotate(addressBT root) {
	addressBT Newroot = (root)->LS;
	addressBT temp = Newroot->RS;

	Newroot->RS = root;
	(root)->LS = temp;

	(root)->tinggi = 1 + (getHeight((root)->LS) > getHeight((root)->RS) ? getHeight((root)->LS) : getHeight((root)->RS));
	Newroot->tinggi = 1 + (getHeight(Newroot->LS) > getHeight(Newroot->RS) ? getHeight(Newroot->LS) : getHeight(Newroot->RS));

	return Newroot;
}

addressBT leftRotate(addressBT root) {
	addressBT Newroot = (root)->RS;
	addressBT temp = Newroot->LS;

	Newroot->LS = root;
	(root)->RS = temp;

	(root)->tinggi = 1 + (getHeight((root)->RS) > getHeight((root)->LS) ? getHeight((root)->RS) : getHeight((root)->LS));
	Newroot->tinggi = 1 + (getHeight(Newroot->RS) > getHeight(Newroot->LS) ? getHeight(Newroot->RS) : getHeight(Newroot->LS));

	return Newroot;
}

int getHeight(addressBT root) {
	if (root == NULL)
		return 0;
	return (root)->tinggi;
}

int getBalanceFactor(addressBT root) {
	if (root == NULL)
		return 0;
	return getHeight(root->LS) - getHeight(root->RS);
}

void PreorderNBT(addressNBT root) {
	if (root == NULL) {
		return;
	}
//	*Newroot = convert(*root, (*root)->info);
	printf("%c ", root->info);  // Print the current node
	PreorderNBT(root->FS);  // Recur on the left subtree
	PreorderNBT(root->NB);  // Recur on the right subtree
}

void PreorderBT(addressBT Newroot) {
	if (Newroot == NULL) {
		return;
	}
//	*Newroot = convert(*root, (*root)->info);
	printf("%c ", (Newroot)->info);  // Print the current node
	PreorderBT(Newroot->LS);  // Recur on the left subtree
	PreorderBT(Newroot->RS);  // Recur on the right subtree
}

void Preorder(addressNBT root, addressBT *Newroot) {
	if (root == NULL) {
		return;
	}
	*Newroot = Convert(*Newroot, root->info);
	if (root->FS != nil) {
		Preorder(root->FS, &(*Newroot)); // Recur on the right subtree
	}
	if (root->NB != nil) {
		Preorder(root->NB, &(*Newroot)); // Recur on the left subtree
	}
}

void deleteTree(addressNBT *Pold) {
	if (Pold == NULL) {
		return;
	}
//	Delete left and right subtrees
//	deleteTree(&(*Pold)->FS);
//	deleteTree(&(*Pold)->NB);
	printf("Deleting node with data: %d\n", (*Pold)->info);
	free(*Pold);
}

boolean Search(addressBT root, infotype X) {
	if (root == NULL) {
		return false;
	}

	if (root->info == X) {
		return true;
	}

	boolean foundLeft = Search(root->LS, X);  // Recur on the left subtree
	boolean foundRight = Search(root->RS, X);  // Recur on the right subtree

	return foundLeft || foundRight;
}

addressBT Convert (addressBT Newroot, infotype X) {
	if (Newroot == nil) return AlokasiBT(X);
	else if (Newroot->info < X) {
		Newroot->RS = Convert(Newroot->RS, X);
	} else {
		Newroot->LS = Convert(Newroot->LS, X);
	}

	Newroot->tinggi =  1 + (getHeight(Newroot->LS) > getHeight(Newroot->RS) ? getHeight(Newroot->LS) : getHeight(Newroot->RS));

	// using balancing factor
	int bFactor = getBalanceFactor(Newroot);

	if (bFactor > 1 && getBalanceFactor(Newroot->LS) > 0) {
		return rightRotate(Newroot);
	} else if (bFactor > 1 && getBalanceFactor(Newroot->LS) <= 0) {
		Newroot->LS = leftRotate(Newroot->LS);
		return rightRotate(Newroot);
	} else if (bFactor < -1 && getBalanceFactor(Newroot->RS) <= 0) {
		return leftRotate(Newroot);
	} else if (bFactor < -1 && getBalanceFactor(Newroot->RS) > 0) {
		Newroot->RS = rightRotate(Newroot->RS);
		return leftRotate(Newroot);
	}
	return Newroot;
}

addressBT convert(addressBT Newroot, infotype X) {
//	addressBT Newroot;
	addressBT Pnew;
//	if (Newroot != nil) {
//		Pnew = Newroot;
//	}

//	if (Newroot == nil)
//		return AlokasiBT(X);

//	if (Newroot == nil) return AlokasiBT(X);
//	else if (Newroot->info < X) {
//		Newroot->RS = Convert(Newroot->RS, X);
//	} else {
//		Newroot->LS = Convert(Newroot->LS, X);
//	}
	if (Newroot == nil) {
		return AlokasiBT(X);
	} else if (Newroot->info < X) {
		Newroot->RS = convert(Newroot->RS, X);
	} else {
		Newroot->LS = convert(Newroot->LS, X);
	}

	Newroot->tinggi = 1 + (getHeight(Newroot->LS) > getHeight(Newroot->RS) ? getHeight(Newroot->LS) : getHeight(Newroot->RS));

	int balanceFactor = getBalanceFactor(Newroot);

	if (balanceFactor > 1 && getBalanceFactor(Newroot->LS) > 0) {
		return rightRotate(Newroot);
	} else if (balanceFactor > 1 && getBalanceFactor(Newroot->LS) <= 0) {
		Newroot->LS = leftRotate(Newroot->LS);
		return rightRotate(Newroot);
	} else if (balanceFactor < -1 && getBalanceFactor(Newroot->RS) <= 0) {
		return leftRotate(Newroot);
	} else if (balanceFactor < -1 && getBalanceFactor(Newroot->RS) > 0) {
		Newroot->RS = rightRotate(Newroot->RS);
		return leftRotate(Newroot);
	}
	return Newroot;
}

void inOrder(addressBT root){
    if (root == NULL) {
        return;
    }
    inOrder(root->LS);
    printf("%c : %d\n", root->info, root->tinggi);
    inOrder(root->RS);
}

void Print_TreeBT(addressBT Newroot, char tab[]) {
	char tempTab[255];
	strcpy(tempTab, tab);
	strcat(tempTab, "-");

	if (Newroot!=NULL) {
		printf("%s%c\n", tab,Newroot->info);
		Print_TreeBT(Newroot ->LS, tempTab);
		Print_TreeBT(Newroot->RS, tab);
	}
}

void Print_TreeNBT(addressNBT root, char tab[]) {
	char tempTab[255];
	strcpy(tempTab, tab);
	strcat(tempTab, "-");

	if (root!=NULL) {
		printf("%s%c\n", tab,root->info);
		Print_TreeNBT(root->FS, tempTab);
		Print_TreeNBT(root->NB, tab);
	}
}

void Tampil_menu() {
	printf("\nPilih menu : ");
	printf("\n1. Create Tree");
	printf("\n2. Convert Tree");
	printf("\n3. Print Tree");
	printf("\n4. Change Theme\n");
}

void loading()
{
	printf("\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\tLoading... \n\n\t\t\t\t");
	printf("\t\t      ");
	for (int i=0; i<=65;i++)
	{
		printf("%c",178);
		Sleep(15);
	}
}
//void deleteTree(addressNBT node) {
//	if (node == NULL)
//		return;
//	if (node->PR->FS->NB == nil)
//		node->PR->FS = nil;
//	else
////		while
//		free(node);
//	deleteTree(node->FS);
//	deleteTree(node->NB);
//}