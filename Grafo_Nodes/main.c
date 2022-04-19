#include <stdio.h>
#include "grafo.h"

int main(void) {
  TipoGrafo *g;
  g = CriarGrafo(3); //cria grafo com 3 nós
  inserirAresta(g,0,1,2,3.3);
  inserirAresta(g,1,2,5,7.5);
  inserirAresta(g,2,0,9,12);
  exibirMatriz(g);
  exibirGrafo(g);

  caminhoMaisCurto(g,0);
  g = liberarGrafo(g);
  return 0;
}