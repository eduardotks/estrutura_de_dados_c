#ifndef TLIST_H_INCLUDED
#define TLIST_H_INCLUDED

//colocar declaração de struct/definições/outros
#include "aluno.h"

#define MAX 100


typedef struct List List;
//************************************************************
//CREATE AREA
List* create_list(); //
//FREE AREA
int free_list(List* li); //
//REALLOC AREA
List* realloc_List(List *li); //
//CONSULT AREA
int consult_List_pos(List* li, int pos, struct aluno *al);
int consult_List_mat(List* li, int mat, struct aluno *al);
//INSERT AREA
int insert_List_inicio(List* li, struct aluno al); //
int insert_List_final(List* li, struct aluno al); //
int insert_List_ordenada(List* li, struct aluno al); //
//REMOVE AREA
int remove_List_inicio(List* li); //
int remove_List_final(List* li); //
int remove_List(List* li, int mat); //
int remove_List_Optimized(List* li, int mat); //
//PRINTF AREA
void print_List(List* li); //
void list_details_qtd(List *li); //
//OTHER AREA
int size_List(List* li); //
int empty_List(List* li); //
int full_List(List* li); //



#endif // TLIST_H_INCLUDED
