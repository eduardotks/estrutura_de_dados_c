#ifndef TQUEUE_H_INCLUDED
#define TQUEUE_H_INCLUDED

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
typedef struct queue Queue;

Queue *queue_create(int size);

//INSERT AREA============================== 1
int queue_push(Queue *qu, struct aluno al);

//REMOVE AREA============================== 2
int queue_pop(Queue *qu);

//FIND AREA================================ 3
int queue_front(Queue *qu, struct aluno *al);

//SIZE AREA================================ 4
int queue_size(Queue *qu);

//OTHERS AREA============================== 5 , 6
int queue_empty(Queue *qu);
int queue_full(Queue *qu);

//FREE AREA================================ 7
int queue_free(Queue *qu);

//COMPACT AREA============================= 8
int compactar_lista(Queue *qu);


#endif // TQUEUE_H_INCLUDED
