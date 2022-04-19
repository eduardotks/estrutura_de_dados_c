#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "TList.h"

//código das funções

struct List
{
    int qtd; //qtd da List
    int qtdInicial; // qtd inicial
    int qtdMax; // qtd final
    struct aluno dados[MAX];
};

//******************FUNÇÕES***********************************
//CREATE AREA
List* create_list()
{
    List *li;
    li = (List*) malloc(sizeof(struct List));
    if(li != NULL)
        li->qtd = 0;
    return li;
}

//FREE AREA
int free_list(List* li)
{
    free(li->dados);
    free(li);
    return 0;
}

//CONSULT AREA
int consult_List_pos(List* li, int pos, struct aluno *al)
{
    if(li == NULL || pos <= 0 ||  pos > li->qtd)
        return 0;
    //modifica o conteúdo do meu ponteiro para a
    //estrutura com os dados da estrutura da posição
    *al = li->dados[pos-1];


    return 1;

}

int consult_List_mat(List* li, int mat, struct aluno *al)
{
    if(li == NULL)//se nulo
        return 0;
    int i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)//se não encontrado
        return 0;

    *al = li->dados[i];
    return 1;
}

//INSERT AREA
int insert_List_inicio(List* li, struct aluno al)
{
    if(li == NULL)//se nulo
        return 0;
    if(li->qtd == MAX)//List cheia
        return 0;
    int i;
    for(i=li->qtd-1; i>=0; i--)
        li->dados[i+1] = li->dados[i];
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

int insert_List_final(List* li, struct aluno al)
{
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)//List cheia
        return 0;
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int insert_List_ordenada(List* li, struct aluno al)
{
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)//List cheia
        return 0;
    int k,i = 0;
    while(i<li->qtd && li->dados[i].matricula < al.matricula)
        i++;

    for(k=li->qtd-1; k >= i; k--)
        li->dados[k+1] = li->dados[k];

    li->dados[i] = al;
    li->qtd++;
    return 1;
}

//REMOVE AREA
int remove_List(List* li, int mat)
{
    if(li == NULL) //se nulo
        return 0;
    if(li->qtd == 0) //se zero
        return 0;
    int k,i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)//se nao encontrado
        return 0;
    for(k=i; k< li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];

    li->qtd--;
    return 1;
}

int remove_List_Optimized(List* li, int mat)
{
    if(li == NULL) //se não existe
        return 0;
    if(li->qtd == 0) //se for zero
        return 0;
    int i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)//se não encontrado
        return 0;

    li->qtd--;
    li->dados[i] = li->dados[li->qtd];
    return 1;
}

int remove_List_inicio(List* li)
{
    if(li == NULL) // se for nulo
        return 0;
    if(li->qtd == 0) //se for zero
        return 0;
    int k = 0;
    for(k=0; k< li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

int remove_List_final(List* li)
{
    if(li == NULL) //se nulo
        return 0;
    if(li->qtd == 0) // se zero
        return 0;
    li->qtd--;
    return 1;
}

//PRINTF AREA
void print_List(List* li)
{
    if(li == NULL) // List nula?
        return;
    if(li->qtd == 0) // quantidade zero?
        printf("\nNada para mostrar!\n");

    int i;
    for(i=0; i<li->qtd; i++)
    {
        printf("\n********************************************");
        printf("\nMATRÍCULA: %d",li->dados[i].matricula);
        printf("\nNOME: %s",li->dados[i].nome);
        printf("\nNOTAS: (%f | %f | %f)",li->dados[i].n1, li->dados[i].n2,li->dados[i].n3);
        printf("\n********************************************\n");
    }
}

void list_details_qtd(List *li)
{
    printf("\n************Relatório da List************\n");
    printf("Quantidade Atual (qtd): %d\n", li->qtd);
    printf("Quantidade Inicial (qtdInicial): %d\n", li->qtdInicial);
    printf("Quantidade Máximo (qtdMAX): %d\n", MAX);
    printf("\n******************************************\n");
}

//OTHER AREA
int size_List(List* li)
{
    if(li == NULL)
        return -1;
    else
        return li->qtd;
}

int empty_List(List* li)
{
    if(li == NULL)
        return -1;
    return (li->qtd == 0);
}

int full_List(List* li)
{
    if(li == NULL)
        return -1;
    return (li->qtd == MAX);
}


