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

void Create_tree(address root) {
	address child, parent, Pnew = root;
	infotype X;
	char c;
	do {
		do {
			if (root == nil) {
				printf("\nMasukan root ");
				X = getche();
				root = Alokasi(X);
			} else {
				parent = Pnew;
				printf("\nMasukan child dari %c ", parent->info);
				if (parent->FS == nil) {
//					child = Alokasi(X);
					parent->FS = Alokasi(X);
				} else { /*if (parent->FS->NB == nil)*/
//			child = Alokasi(X);
					child = parent->FS;
					while (child->NB != nil) {
						child = child->NB;
					}
					child->NB = Alokasi(X);
				}
			}
			Pnew = parent->FS;
//			parent = root;
			c = getch();
			if (c == 'y' || c == 'Y') {
				printf("\nInsert child lagi untuk %c?", parent->info);
			} else {
				printf("\nInsert child untuk %c? ", parent->info);
			}
		} while (c == 'y' || c == 'Y');
		if (parent->FS != nil) {
			printf("\nNext parent?");
			c = getch();
			if(c == 'y' || c =='Y') {
				if (parent->FS != nil) {
					parent = parent->FS;
				} else {
					parent = parent->NB;
				}
			}
		}
	} while (c == 'y' || c == 'Y');
}

//int Count (address X) {
//	int j = 1;
//	address Pcur = 1;
//	boolean Status = true;
//	do {
//		if (X[Pcur].ps_fs != nil && Status == true) {
//			Pcur = X[Pcur].ps_fs;
//			j++;
//		} else if (X[Pcur].ps_nb != nil) {
//			Pcur = X[Pcur].ps_nb;
//			j++;
//			Status = true;
//		} else {
//			Pcur = X[Pcur].ps_pr;
//			Status = false;
//		}
//	} while(X[Pcur].ps_pr != nil);
//	return j;
//}
//
//
//void InOrder (address P) {
//	address Pcur = 1;
//	boolean Status = true;
//
//	while(Pcur != nil) {
//		if(P[Pcur].ps_fs != nil && Status == true) {
//			Pcur = P[Pcur].ps_fs;
//		} else {
//			if(Status) {
//				printf("%c ", P[Pcur].info);
//			}
//
//			if(Pcur == P[P[Pcur].ps_pr].ps_fs) {
//				printf("%c ", P[P[Pcur].ps_pr].info);
//			}
//
//			if(P[Pcur].ps_nb != nil) {
//				Pcur = P[Pcur].ps_nb;
//				Status = true;
//			} else {
//				Pcur = P[Pcur].ps_pr;
//				Status = false;
//			}
//		}
//	}
//}
//
//void PostOrder (address P) {
//	address Pcur = 1;
//	boolean Status = true;
//	while(Pcur != nil) {
//		if(P[Pcur].ps_fs && Status == true) {
//			Pcur = P[Pcur].ps_fs;
//		} else {
//			printf("%c ", P[Pcur].info);
//			if(P[Pcur].ps_nb != nil) {
//				Pcur = P[Pcur].ps_nb;
//				Status = true;
//			} else {
//				Pcur = P[Pcur].ps_pr;
//				Status = false;
//			}
//		}
//	}
//}
//
//int Level (address P, infotype X) {
//	address Current = 1;
//	address hitung = nil;
//	boolean kondisi = true;
//	while (P[Current].info != X) {
//		Current++;
//	}
//	while (P[Current].ps_pr != nil) {
//		Current = P[Current].ps_pr;
//		hitung++;
//	}
//	return hitung;
//}
//return hitung;
//}