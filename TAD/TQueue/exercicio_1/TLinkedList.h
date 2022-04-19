#ifndef TLINKEDLIST_H_INCLUDED
#define TLINKEDLIST_H_INCLUDED

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define ERRO -5

#include "aluno.h"

//expondo como é a lista sem mostrar a estrutura
typedef struct list List;

List* list_create();

//INSERT AREA

int list_push_front(List *li, struct aluno al);          //1
int list_push_back(List *li, struct aluno al);           //2
int list_insert(List *li, int pos, struct aluno al);     //3
int list_insert_sorted(List *li, struct aluno al);       //4

//REMOVE/ERASE AREA
int list_pop_front(List *li);                            //5
int list_pop_back(List *li);                             //6
int list_erase(List *li, int mat);                       //7

//GET AREA
int list_find_pos(List *li, int pos, struct aluno *al);  //8
int list_find_mat(List *li, int nmat, struct aluno *al); //9
int list_get_pos(List *li, int nmat, int *pos);          //10
int list_print(List *li);                                //11

//FREE AREA
int list_free(List *li);                                 //12

//SIZE AREA
int list_size(List *li);                                 //13

//OTHERS AREA
int list_full(List *li);
int list_empty(List *li);

#endif // TLINKEDLIST_H_INCLUDED
