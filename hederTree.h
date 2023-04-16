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
typedef struct bt* address;
typedef struct bt{
	infotype info;
	address LS;
	address RS;
	int tinggi;
} AVL;

/***************************/
/* S P E S I F I K A S I */
/***************************/

void Create_tree(address X);
// Create Non Binary Tree sebanyak Jml_Node
// Tujuan mengentrykan Non Binary Tree ke array AVL dengan pola Level Order
// Jml Node adalah banyaknya elemen dalam Tree yang menjadi parameter input
boolean IsEmpty (AVL P);
/* Mengirimkan true jika AVL KOSONG */
/***** Traversal *****/
int Count (AVL P);
/* Traversal PreOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PreOrder : Parent, fs, nb */
void InOrder (AVL P);
/* Traversal InOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara InOrder : fs, Parent, Sisa anak lain */
void PostOrder (AVL P);
/* Traversal PostOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PostOrder : fs, nb, Parent */
void Level_order(AVL X);
/* Traversal LevelOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara Level Order */
void PrintTree (AVL P);
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditulis ke layar */
/***** Search *****/
boolean Search (AVL P, infotype X);
/* Mengirimkan true jika ada nodedari P yang bernilai X *
/***** Fungsi Lain *****/
int nbElmt (AVL P);
/* Mengirimkan banyak elemen (node) di pohon non biner P */
int nbDaun (AVL P);
/* Mengirimkan banyak daun (node) pohon non biner P */
int Level (AVL P, infotype X);
/* Mengirimkan level dari node X yang merupakan salah satu simpul */
/* dr pohon P. Akar (P) levelnya adalah 0. Pohon tidak kosong */
int Depth (AVL P);
/* Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari Pohon */
/* Basis : Pohon Kosong, tingginya Nol */
int Max (infotype Data1, infotype Data2);
/* Mengirimkan Nilai terbesar dari dua data */
void Kosong(AVL X, int Jml_Node);
#endif