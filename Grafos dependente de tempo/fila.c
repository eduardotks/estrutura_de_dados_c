#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
void IniciaFila(TipoFila *fila){
   fila->inicio = NULL;
   fila->fim = NULL;
   fila->tamanho=0;
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
int Vazia(TipoFila *fila){
   return (fila->inicio == NULL);
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
void Esvazia(TipoFila *fila) {
  while(!Vazia(fila)) {
    Desenfileira(fila);
  }
  fila->inicio = NULL;
  fila->fim = NULL;
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
void Libera(TipoFila *fila) {
  Esvazia(fila);
  fila = NULL;
  free(fila);
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
void Enfileira(int x, TipoFila *fila){
   TipoNo *aux;
   aux = (TipoNo *) malloc(sizeof(TipoNo));
   if(aux == NULL)
   {
       return;
   }
   aux->valor=x;
   aux->prox=NULL;
   if (Vazia(fila)){
      fila->inicio=aux;
      fila->fim=aux;
   }
   else {
      fila->fim->prox = aux;
      fila->fim = aux;
   }
   fila->tamanho++;
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
int Desenfileira(TipoFila *fila){
   TipoNo *q; int v;
   if (Vazia(fila)) {
      return 0;
   }
   q = fila->inicio;
   v = fila->inicio->valor;
   fila->inicio = fila->inicio->prox;
   free(q);
   fila->tamanho--;
   return v;
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

