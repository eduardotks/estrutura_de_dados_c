#ifndef TQUEUE_H_INCLUDED
#define TQUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
//import dos arquivos H
#include "aluno.h"
#include "TLinkedList.h"

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define ERRO -5

typedef struct queue Queue;
typedef struct aluno Aluno;

Queue *queue_create();

//INSERT AREA============================== 1
int queue_push(Queue *tmp, struct aluno al);

//REMOVE AREA============================== 2
int queue_pop(Queue *tmp);

//FIND POSITION============================ 3
int queue_front(Queue *tmp, struct aluno *al);

//SIZE AREA================================ 4
int queue_size(Queue *tmp);

//OTHERS AREA============================== 5 , 6
int queue_empty(Queue *tmp);

int queue_full(Queue *tmp);

//FREE AREA================================ 7
int queue_free(Queue *tmp);

#endif // TQUEUE_H_INCLUDED
