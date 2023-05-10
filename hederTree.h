#ifndef nbtrees_h
#define nbtrees_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <MMsystem.h>
#include "boolean.h"

//Maksimal node yang dapat ditampung dalam array
#define jml_maks 20

//Arah traversal
#define kebawah 1
#define keatas 2
#define kekanan 3
#define nil NULL

/***************************/
/* Type data */
/***************************/
/* Indeks dalam bahasa C dimulai dengan 0; tetapi indeks 0 tidak dipakai */
/* Kamus */
typedef char infotype;
typedef struct nbt *addressNBT;
typedef struct nbt{
	infotype info;
	addressNBT FS;
	addressNBT NB;
	addressNBT PR;
} NBT;

typedef struct bt *addressBT;
typedef struct bt{
	infotype info;
	addressBT LS;
	addressBT RS;
	int tinggi;
} AVL;

typedef struct {
	addressBT Newroot;
}First;

/***************************/
/* S P E S I F I K A S I */
/***************************/

void Create_tree(addressNBT *root, int Jml_Node);

//void Print_Tree (address root, char tab[]);

void Tampil_menu();

addressNBT AlokasiNBT(infotype X);

addressBT rightRotate(addressBT root);

addressBT leftRotate(addressBT root);

int getHeight(addressBT root);

int getBalanceFactor(addressBT root);

addressBT convert(addressBT Newroot, infotype X);

addressBT Convert (addressBT Newroot, infotype X);

void Preorder(addressNBT root, addressBT *Newroot);

void PreorderNBT(addressNBT root);

void PreorderBT(addressBT Newroot);

void Print_TreeNBT(addressNBT root, char tab[]);

void Print_TreeBT(addressBT Newroot, char tab[]);

//void inorder(address root);

#endif
