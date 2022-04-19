#ifndef TDLINKEDLIST_H_INCLUDED
#define TDLINKEDLIST_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define ERRO -5

struct aluno
{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};
typedef struct DlinkedList List;

//CREATE AREA
List* list_create();

//INSERT AREA
int list_push_front(List *li, struct aluno al);          //1
int list_push_back(List *li, struct aluno al);           //2
int list_insert(List *li, int pos, struct aluno al);     //3

//REMOVE/ERASE AREA
int list_pop_front(List *li);                            //4
int list_pop_back(List *li);                             //5
int list_erase(List *li, int pos);                       //6

//GET AREA
int list_find_pos(List *li, int pos, struct aluno *al);  //7
int list_find_mat(List *li, int nmat, struct aluno *al); //8
int list_front(List *li, struct aluno *al);              //9
int list_back(List *li, struct aluno *al);               //10
int list_get_pos(List *li, int nmat, int *pos);          //11

//PRINT AREA
int list_print_forward(List *li);                        //12
int list_print_reverse(List *li);                        //13

//FREE AREA
int list_free(List *li);                                 //14

//SIZE AREA
int list_size(List *li);                                 //15

#endif // TDLINKEDLIST_H_INCLUDED
