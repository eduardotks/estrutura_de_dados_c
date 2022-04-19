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
    //---------------INÍ. ARESTAS-------------------
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

    //-----------------INÍ. TEMPO-------------------
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
    printf("\n\t\t\t << Quadro de Informações >> \n");
    printf("\nPrimeira Chegada do Transp.: %d\n", primeiraChegada(grafo, 0, 1));
    printf("\nÚltima Saída do Transp.: %d\n", ultimaSaida(grafo, 2, 0));
    printf("\nTempo da viagem de menor duração: [(Início): %d Hora(s) >> (Fim): %d Hora(s) ] - Duração (Tempo Total) : %d Hora(s)", Entrada, Saida, viagemMenorDuracao(grafo, 0, 1, &Entrada, &Saida));
    printf("\n");
    printf("****************************************************************************");
    printf("\n\n");
    //----------------------------------------------------

    //===========================================================================
    //===========================================================================
    //===========================================================================


    //-----------------VALIDAÇÃO-------------------
    printf("****************************************************************************");
    printf("\n\t\t\t << vERIFICAÇÃO DE CAMINHO VÁLIDO >> \n");

    printf("\nCaminho 0 --> 2 válido?");
    verificaCaminho(grafo, 0, 2);
    printf("\nCaminho 1 --> 2 válido?");
    verificaCaminho(grafo, 1, 2);
    printf("\nCaminho 0 --> 1 válido?");
    verificaCaminho(grafo, 0, 1);
    printf("\nCaminho 2 --> 3 válido?");
    verificaCaminho(grafo, 2, 3);
    printf("\nCaminho 3 --> 0 válido?");
    verificaCaminho(grafo, 3, 0);

    printf("\n");
    printf("****************************************************************************");
    return 0;
}





