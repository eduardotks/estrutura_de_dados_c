#ifndef TCIRCULAR_H_INCLUDED
#define TCIRCULAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define ERRO -5

typedef struct listcircular ListCircular;
typedef struct listnode ListNode;
typedef struct aluno Aluno;

//CREATE AREA
ListCircular *list_create();

//INSERT AREA
int list_push_begin(ListCircular *LiCi, Aluno al); //COMECO
int list_push_end(ListCircular *LiCi, Aluno al); //FINAL 2
int list_push_pos(ListCircular *LiCi, int pos, Aluno al); //POSICAO 3

//REMOVE AREA
int list_remove_begin(ListCircular *LiCi); //COMECO 4
int list_remove_end(ListCircular *LiCi); //FINAL 5
int list_remove_mat(ListCircular *LiCi, int mat); //REMOVE MATRICULA 6
int list_remove_pos(ListCircular *LiCi, int pos); //REMOVE POR POSICAO 7

//PRINT AREA
int list_print(ListCircular *LiCi); //8

//PRINT AREA
int list_select_begin(ListCircular *LiCi, Aluno *al); //9
int list_select_end(ListCircular *LiCi, Aluno *al); //10
int list_select_mat(ListCircular *LiCi, int mat, Aluno *al);  //11
int list_select_pos(ListCircular *LiCi, int pos, Aluno *al); //12


#endif // TCIRCULAR_H_INCLUDED
