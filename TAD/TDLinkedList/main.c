#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "TDLinkedList.h"


int main()
{
    setlocale(LC_ALL, "Portuguese");

    //------------------------------------------------------------------
    int i = 0, tamanho = 0, res = 0, caseUse = 0, pos = 0, mat = 0;
    struct aluno al;
    //------------------------------------------------------------------
    printf("Digite o tamanho que será alocado: ");
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
        printf("Digite uma opção");
        //INSERT AREA
        printf("\n 1  - list_push_front     (inserir no início)");
        printf("\n 2  - list_push_back      (inserir no final)");
        printf("\n 3  - list_insert         (inserir por posição)");

        //REMOVE/ERASE AREA
        printf("\n 4  - list_pop_front      (remover do início)");
        printf("\n 5  - list_pop_back       (remover do final)");
        printf("\n 6  - list_erase          (apagar elemento da lista por posição)");

        //GET AREA
        printf("\n 7  - list_find_pos       (encontrar por posição)");
        printf("\n 8  - list_find_mat       (encontrar por matrícula)");
        printf("\n 9  - list_front          ");
        printf("\n 10 - list_back           ");
        printf("\n 11 - list_get_pos        (retornar posição do aluno)");

        //PRINT AREA
        printf("\n 12 - list_print_forward  (mostrar informações)");
        printf("\n 13 - list_print_reverse  (mostrar informações inversa)");

        //FREE AREA
        printf("\n 14 - list_free           (desalocar lista)");
        //SIZE AREA
        printf("\n 15 - list_size           (tamanho da lista)");
        printf("\n 16 - Sair");

        printf("\n********************************************\n");
        scanf(" %d", &caseUse);

        switch (caseUse)
        {

        case 1:
            //------------------------------------------------
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
                printf("\nDigite o número da matrícula: \n");
                scanf(" %d",&al.matricula);
                getchar();
                printf("\nDigite o nome do aluno: \n");
                fgets(al.nome,30,stdin);
                al.nome[strcspn(al.nome, "\n")] = 0;

                printf("Digite a 1º nota: \n");
                scanf(" %f",&al.n1);
                getchar();
                printf("Digite a 2º nota: \n");
                scanf(" %f",&al.n2);
                getchar();
                printf("Digite a 3º nota: \n");
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
                printf("\nDigite a posição para fazer a inserção (digite 1 se for o primeiro elemento): ");
                scanf(" %d", &pos);
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
            //------------------------
            list_pop_front(li);
            break;

        //------------------------

        case 5:

            //-------------------------

            list_pop_back(li);
            break;

        //------------------------

        case 6:
            //----------------------------
            printf("\nDigite a posição do node que será removida: \n");
            scanf(" %d",&pos);
            getchar();
            list_erase(li,pos);
            break;
        //---------------------------

        case 7:
            //------------------------------
            pos = 0;
            printf("Digite a posição: ");
            scanf("%d", &pos);
            list_find_pos(li,pos,&al);
            break;
        //------------------------------

        case 8:
            //-----------------------------
            printf("\nDigite a matrícula: ");
            mat = 0;
            scanf("%d", &mat);
            list_find_mat(li,mat,&al);
            break;
        //-----------------------------
        case 9:
            //-----------------------------
            list_front(li,&al);
            list_print_forward(li);
            break;
        //-----------------------------
        case 10:
            //-----------------------------
            list_back(li,&al);
            list_print_forward(li);
            break;
        //-----------------------------
        case 11:
            //-----------------------------
            mat = 0;
            printf("\nDigite a matrícula: \n");
            scanf(" %d",&mat);
            getchar();
            res = 0;
            res = list_get_pos(li,mat, &pos);
            printf("%d \n", res);
            break;
        //-----------------------------
        case 12:
            list_print_forward(li);
            break;

        case 13:
            //----------------------------
            list_print_reverse(li);
            break;
        //----------------------------


        case 14:
            //----------------------------
            printf("\nO programa foi finalizado!");
            return 15;
        //----------------------------

        case 15:
            //----------------------------
            tamanho = 0;
            tamanho = list_size(li);
            printf("\nTamanho da lista: %d\n", tamanho);
            break;
            //----------------------------

        }
    }
    while(caseUse != 15);

    return 0;
}


