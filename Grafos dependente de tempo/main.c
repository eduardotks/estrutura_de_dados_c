#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese"); //add suporte p/ texto pt-br
    Grafo grafo;
    //VAR
    int Entrada = 0;
    int Saida = 0;
    //CRIA GRAFO
    grafo = criarGrafo(4);
    //---------------IN�. ARESTAS-------------------
    //INSERE ARESTAS

    inserirArestas(grafo,0,1);
    inserirArestas(grafo,1,2);
    inserirArestas(grafo,2,0);
    inserirArestas(grafo,2,3);

    //PRINT ARESTAS
    printf("****************************************************************************");
    printf("\n\t\t\t << Lista de Adjacencias Inicial >>\n");
    imprimirListaAdj(grafo); //print
    printf("\n");
    printf("****************************************************************************");
    printf("\n\n");
    //---------------FIM ARESTAS--------------------

    //===========================================================================
    //===========================================================================
    //===========================================================================

    //-----------------IN�. TEMPO-------------------
    //INSERE TEMPO

    insertTempoComVerificacao(grafo, 0, 1, 2, 3);
    insertTempoComVerificacao(grafo, 1, 2, 5, 7);
    insertTempoComVerificacao(grafo, 2, 0, 9, 12);
    insertTempoComVerificacao(grafo, 2, 3, 8, 9);

    //PRINT TEMPO
    printf("****************************************************************************");
    printf("\n\t\t\t << L. de Adjacencias com Tempo >> \n");
    imprimirListaAdj(grafo);
    printf("\n");
    printf("****************************************************************************");
    //---------------FIM TEMPO--------------------

    //===========================================================================
    //===========================================================================
    //===========================================================================

    //-----------------MORE INFORMATION-------------------
    printf("\n\n");
    printf("****************************************************************************");
    printf("\n\t\t\t << Quadro de Informa��es >> \n");
    printf("\nPrimeira Chegada do Transp.: %d\n", primeiraChegada(grafo, 0, 1));
    printf("\n�ltima Sa�da do Transp.: %d\n", ultimaSaida(grafo, 2, 0));
    printf("\nTempo da viagem de menor dura��o: [(In�cio): %d Hora(s) >> (Fim): %d Hora(s) ] - Dura��o (Tempo Total) : %d Hora(s)", Entrada, Saida, viagemMenorDuracao(grafo, 0, 1, &Entrada, &Saida));
    printf("\n");
    printf("****************************************************************************");
    printf("\n\n");
    //----------------------------------------------------

    //===========================================================================
    //===========================================================================
    //===========================================================================


    //-----------------VALIDA��O-------------------
    printf("****************************************************************************");
    printf("\n\t\t\t << vERIFICA��O DE CAMINHO V�LIDO >> \n");

    printf("\nCaminho 0 --> 2 v�lido?");
    verificaCaminho(grafo, 0, 2);
    printf("\nCaminho 1 --> 2 v�lido?");
    verificaCaminho(grafo, 1, 2);
    printf("\nCaminho 0 --> 1 v�lido?");
    verificaCaminho(grafo, 0, 1);
    printf("\nCaminho 2 --> 3 v�lido?");
    verificaCaminho(grafo, 2, 3);
    printf("\nCaminho 3 --> 0 v�lido?");
    verificaCaminho(grafo, 3, 0);

    printf("\n");
    printf("****************************************************************************");
    return 0;
}





