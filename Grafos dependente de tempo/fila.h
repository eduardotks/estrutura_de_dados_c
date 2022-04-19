#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include "no.h"

typedef struct Fila
{
   TipoNo *inicio, *fim;
   int tamanho;
} TipoFila;


void IniciaFila(TipoFila *fila); //OK

int Vazia(TipoFila *fila); //OK

void Esvazia(TipoFila *fila); //OK

void Libera(TipoFila *fila); //OK

void Enfileira(int x, TipoFila *fila); //OK

int Desenfileira(TipoFila *fila); //OK

#endif // FILA_H_INCLUDED

