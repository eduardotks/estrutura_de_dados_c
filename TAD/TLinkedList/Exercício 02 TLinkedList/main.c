#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "TLinkedList.h"
int main()
{
    setlocale(LC_ALL, "Portuguese");
    //------------------------------------------------------------------
    int i = 0, tamanho = 0, res = 0, caseUse = 0, pos = 0, mat = 0;
    struct aluno al;
    //------------------------------------------------------------------
    printf("Digite o tamanho que ser� alocado: ");
    scanf("%d",&tamanho);

    List *li = list_create(tamanho);

    if(li == NULL)
    {
        printf("Erro!");
        return INVALID_NULL_POINTER;
    }

    do
    {
        printf("\n********************************************\n");
        printf("<< Cadastro de Aluno >> \n");
        printf("Digite uma op��o");
        printf("\n 1  - list_push_front     (inserir no in�cio)");
        printf("\n 2  - list_push_back      (inserir no final)");
        printf("\n 3  - list_insert         (inserir por posi��o)");
        printf("\n 4  - list_insert_sorted  (inserir ordenada)");

        printf("\n 5  - list_pop_front      (remover do in�cio)");
        printf("\n 6  - list_pop_back       (remover do final)");
        printf("\n 7  - list_erase          (apagar elemento da lista por posi��o)");

        printf("\n 8  - list_find_pos       (encontrar por posi��o)");
        printf("\n 9  - list_find_mat       (encontrar por matr�cula)");
        printf("\n 10 - list_get_pos        (retornar posi��o do aluno)");
        printf("\n 11 - list_print          (mostrar informa��es)");

        printf("\n 12 - list_free           (desalocar lista)");

        printf("\n 13 - list_size           (tamanho da lista)");
        printf("\n 14 - Sair");

        printf("\n********************************************\n");
        scanf(" %d", &caseUse);

        switch (caseUse)
        {

        case 1:
            //------------------------------------------------
            for(i = 0; i < tamanho; i++)
            {
                printf("\nDigite o n�mero da matr�cula: \n");
                scanf(" %d",&al.matricula);
                getchar();
                printf("\nDigite o nome do aluno: \n");
                fgets(al.nome,30,stdin);
                printf("Digite a 1� nota: \n");
                scanf(" %f",&al.n1);
                getchar();
                printf("Digite a 2� nota: \n");
                scanf(" %f",&al.n2);
                getchar();
                printf("Digite a 3� nota: \n");
                scanf(" %f",&al.n3);
                getchar();
                res = list_push_front(li, al);
                if(res != SUCCESS)
                {
                    printf("Erro ao inserir aluno.");
                    return OUT_OF_RANGE;
                }
            }
            break;
        //------------------------------------------------


        case 2:
            //------------------------------------------------
            for(i = 0; i < tamanho; i++)
            {
                printf("\nDigite o n�mero da matr�cula: \n");
                scanf(" %d",&al.matricula);
                getchar();
                printf("\nDigite o nome do aluno: \n");
                fgets(al.nome,30,stdin);
                al.nome[strcspn(al.nome, "\n")] = 0;

                printf("Digite a 1� nota: \n");
                scanf(" %f",&al.n1);
                getchar();
                printf("Digite a 2� nota: \n");
                scanf(" %f",&al.n2);
                getchar();
                printf("Digite a 3� nota: \n");
                scanf(" %f",&al.n3);
                getchar();
                res = list_push_back(li, al);
                if(res != SUCCESS)
                {
                    printf("Erro ao inserir aluno.");
                    return OUT_OF_RANGE;
                }
            }
            break;
        //------------------------------------------------


        case 3:

            //--------------------------------------------
            for(i = 0; i < tamanho; i++)
            {
                printf("\nDigite a posi��o para fazer a inser��o (digite 1 se for o primeiro elemento): ");
                scanf(" %d", &pos);
                printf("\nDigite o n�mero da matr�cula: \n");
                scanf(" %d",&al.matricula);
                getchar();
                printf("\nDigite o nome do aluno: \n");
                fgets(al.nome,30,stdin);
                printf("Digite a 1� nota: \n");
                scanf(" %f",&al.n1);
                getchar();
                printf("Digite a 2� nota: \n");
                scanf(" %f",&al.n2);
                getchar();
                printf("Digite a 3� nota: \n");
                scanf(" %f",&al.n3);
                getchar();
                res = list_insert(li,pos,al);
                if(res != SUCCESS)
                {
                    printf("Erro ao inserir aluno.");
                    return OUT_OF_RANGE;
                }
            }

            break;
        //--------------------------------------------


        case 4:
            //--------------------------------------------
            for(i = 0; i < tamanho; i++)
            {
                printf("\nDigite o n�mero da matr�cula: \n");
                scanf(" %d",&al.matricula);
                getchar();
                printf("\nDigite o nome do aluno: \n");
                fgets(al.nome,30,stdin);
                printf("Digite a 1� nota: \n");
                scanf(" %f",&al.n1);
                getchar();
                printf("Digite a 2� nota: \n");
                scanf(" %f",&al.n2);
                getchar();
                printf("Digite a 3� nota: \n");
                scanf(" %f",&al.n3);
                getchar();
                res = list_insert_sorted(li, al);
                if(res != SUCCESS)
                {
                    printf("Erro ao inserir aluno.");
                    exit(1);
                }
            }
            break;

        //--------------------------------------------

        case 5:
            //------------------------
            list_pop_front(li);
            break;

        //------------------------

        case 6:

            //-------------------------

            list_pop_back(li);
            break;

        //------------------------

        case 7:
            //----------------------------
            printf("\nDigite a posi��o do node que ser� removida: \n");
            scanf(" %d",&pos);
            getchar();
            list_erase(li,pos);
            break;
        //---------------------------

        case 8:
            //------------------------------
            pos = 0;
            printf("Digite a posi��o: ");
            scanf("%d", &pos);
            list_find_pos(li,pos,&al);
            list_print(li);
            break;
        //------------------------------

        case 9:
            //-----------------------------
            printf("\nDigite a matr�cula: ");
            mat = 0;
            scanf("%d", &mat);
            list_find_mat(li,mat,&al);
            list_print(li);
            break;
        //-----------------------------
        case 10:
            //-----------------------------
            mat = 0;
            printf("\nDigite a matr�cula: \n");
            scanf(" %d",&mat);
            getchar();
            list_get_pos(li,mat,pos);
            break;
        //-----------------------------
        case 11:
            list_print(li);
            break;

        case 12:
            //----------------------------
            list_free(li);
            break;
        //----------------------------


        case 13:
            //----------------------------

            tamanho = 0;
            tamanho = list_size(li);
            printf("\nTamanho da lista: %d\n", tamanho);
            break;
        //----------------------------

        case 14:
            //----------------------------

            printf("\nFim do programa!");
            break;
            //----------------------------

        }
    }
    while(caseUse != 14);

    return 0;
}

