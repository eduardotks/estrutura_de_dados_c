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

typedef struct aluno Aluno;

//STRUCT 1
typedef struct listcircular ListCircular;
//STRUCT 2
typedef struct listnode ListNode;

//CREATE AREA
ListCircular *list_create();

//INSERT AREA
int list_push_begin(ListCircular *cL, Aluno al);    //1
int list_push_end(ListCircular *cL, Aluno al);      //2

//REMOVE AREA
int list_remove_begin(ListCircular *cL);            //3
int list_remove_end(ListCircular *cL);              //4

//PRINT/GET AREA
int list_select_begin(ListCircular *cL, Aluno *al); //5
int list_select_end(ListCircular *cL, Aluno *al);   //6
ListNode *list_select_next(ListCircular *cL, Aluno *al);    //7

//FREE AREA
int list_free(ListCircular *cl);    //8


#endif // TCIRCULAR_H_INCLUDED
