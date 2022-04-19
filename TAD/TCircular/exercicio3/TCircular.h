#ifndef TCIRCULAR_H_INCLUDED
#define TCIRCULAR_H_INCLUDED

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define ERRO -5

#include <stdio.h>
#include <stdlib.h>
#include "carro.h"

typedef struct listcircular ListCircular;
typedef struct listnode ListNode;
typedef struct carro Carro;

//CREATE AREA
ListCircular *list_create();
//INSERT AREA
int list_push_begin(ListCircular *cL, Carro p);
int list_push_end(ListCircular *cL, Carro p);
//REMOVE AREA
int list_remove_begin(ListCircular *cL);
int list_remove_end(ListCircular *cL);
//PRINT
void list_print(ListCircular *cL);
//ARM
int list_data(ListCircular *cL, Carro *c);

#endif // TCIRCULAR_H_INCLUDED
