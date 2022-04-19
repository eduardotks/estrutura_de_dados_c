#ifndef TMATRIZ_H_INCLUDED
#define TMATRIZ_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct matriz Matriz;

//CREATE AREA
//Cria matriz de acordo com as dimens�es de entrada da matriz
Matriz *matriz_create(int nlinha, int ncoluna);

//INSERT AREA
//adiciona um inteiro em uma posi��o espec�fica da matriz
int matriz_insert(Matriz *n, int i, int j, int val);

//Preenche toda a matriz com valor inteiro passado por par�metro
int matriz_fill(Matriz *n, int val);

//SELECT
//Seleciona elemento da lista
int matriz_select(Matriz *n, int i, int j, int* val);

//Atribui a dimens�o da Matriz m em nLin e nCol
int matriz_get_lin_col(Matriz *m, int *nLin, int *nCol);

//PRINT AREA
//Imprime a tad de entrada na tela
int matriz_print(Matriz *m);

//FREE AREA
//libera mem�ria
int matriz_free(Matriz *n);

#endif // TMATRIZ_H_INCLUDED
