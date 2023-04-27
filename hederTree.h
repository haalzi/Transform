#ifndef nbtrees_h
#define nbtrees_h
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "boolean.h"

//Maksimal node yang dapat ditampung dalam array
#define jml_maks 20

//Arah traversal
#define kebawah 1
#define keatas 2
#define kekanan 3
#define nil NULL
#define FS LS
#define NB RS

/***************************/
/* Type data */
/***************************/
/* Indeks dalam bahasa C dimulai dengan 0; tetapi indeks 0 tidak dipakai */
/* Kamus */
typedef char infotype;
typedef struct bt *address;
typedef struct bt{
	infotype info;
	address LS;
	address RS;
	address PR;
	int tinggi;
} AVL;

/***************************/
/* S P E S I F I K A S I */
/***************************/

void Create_tree(address *root, int Jml_Node);

void Print_Tree (address root, char tab[]);

void Tampil_menu();

address Alokasi(infotype X);

#endif
