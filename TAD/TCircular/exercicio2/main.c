#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "TCircular.h"

int main()
{
    //pt-br
    setlocale(LC_ALL, "Portuguese");
    //------------------------------------------------------
    int i = 0, tamanho = 0, res = 0, caseUse = 0;
    struct aluno al;
    ListCircular *cl = NULL;
    //------------------------------------------------------

    printf("Quantos deseja inserir? ");
    scanf("%d",&tamanho);

    cl = list_create();
    //se a criação da lista falhar
    if(cl == NULL)
    {
        printf("Erro!");
        return INVALID_NULL_POINTER;
    }

    do
    {
        printf("\n****************************************************\n");
        printf("<< Cadastro de Aluno - LISTA CIRCULAR >> \n");
        printf("Digite uma opção");
        //insert area
        printf("\n 1 - list_push_begin");       //insere
        printf("\n 2 - list_push_end");         //insere
        //remove area
        printf("\n 3 - list_remove_begin");     //remove
        printf("\n 4 - list_remove_end");       //remove
        //print area
        printf("\n 5 - list_select_begin");     //print
        printf("\n 6 - list_select_end");       //print
        printf("\n 7 - list_select_next");      //print
        //FREE
        printf("\n 8 - list_free");             //free
        //EXIT
        printf("\n 9 - Sair"); //sair

        printf("\n****************************************************\n");
        scanf(" %d", &caseUse);

        switch (caseUse)
        {

        case 1:
            for(i = 0; i < tamanho; i++)
            {
                printf("\nDigite o número da matrícula: \n");
                scanf(" %d",&al.matricula);
                getchar();
                printf("\nDigite o nome do aluno: \n");
                fgets(al.nome,30,stdin);
                printf("Digite a 1º nota: \n");
                scanf(" %f",&al.n1);
                getchar();
                printf("Digite a 2º nota: \n");
                scanf(" %f",&al.n2);
                getchar();
                printf("Digite a 3º nota: \n");
                scanf(" %f",&al.n3);
                getchar();
                res = list_push_begin(cl, al);
                if(res == INVALID_NULL_POINTER)
                {
                    return ERRO;
                }
            }
            break;


        case 2:

            for(i = 0; i < tamanho; i++)
            {
                printf("\nDigite o número da matrícula: \n");
                scanf(" %d",&al.matricula);
                getchar();
                printf("\nDigite o nome do aluno: \n");
                fgets(al.nome,30,stdin);
                printf("Digite a 1º nota: \n");
                scanf(" %f",&al.n1);
                getchar();
                printf("Digite a 2º nota: \n");
                scanf(" %f",&al.n2);
                getchar();
                printf("Digite a 3º nota: \n");
                scanf(" %f",&al.n3);
                getchar();
                res = list_push_end(cl, al);
                if(res == INVALID_NULL_POINTER)
                {
                    return ERRO;
                }
            }
            break;

        case 3:
            list_remove_begin(cl);
            printf("\nRemovi do começo!!!");
            break;

        case 4:
            list_remove_end(cl);
            printf("\nRemovi no final!!!");
            break;

        case 5:
            list_select_begin(cl, &al);
            break;

        case 6:
            list_select_end(cl, &al);
            break;

        case 7:
            list_select_next(cl, &al);
            break;

        case 8:
            list_free(cl);
            printf("\nliberada!!!");
            break;

        case 9:
            printf("\nFim do programa!");
            break;

        }
    }
    while(caseUse != 9);

    return 0;
}

