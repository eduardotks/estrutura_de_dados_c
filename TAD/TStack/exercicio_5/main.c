#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#include "TStack.h"

char *infixaParaPosfixa(char *inf);


int main()
{
    //***************************************************
    setlocale(LC_ALL, "Portuguese");
    //***************************************************

    //inserindo expressão de teste
    char inf[100] = {"(5 *(((9 +8 )*(4 *6 ))+7 ))"};

    //***************************************************

    char *posfixo;
    posfixo = infixaParaPosfixa(inf);
    printf("Forma postfix: %s\n\n", posfixo);

    return 0;
}


char *infixaParaPosfixa (char *inf)
{
    Stack *st = NULL;
    int n = strlen (inf);
    char *posfixo;
    posfixo = malloc ((n+1) * sizeof (char));
    st = stack_create(); //func para criapilha
    stack_push(st, inf[0]); //func para empilha

    int j = 0;
    for (int i = 1; inf[i] != '\0'; ++i)
    {
        switch (inf[i])
        {
            char x;
        case '(':
            stack_push(st, inf[i]);   //func para empilha
            break;
        case ')':
            x = stack_pop(st);        //func para desempilha
            while (x != '(')
            {
                posfixo[j++] = x;
                x = stack_pop(st);     //func para desempilha
            }
            break;
        case '+':
        case '-':
            x = stack_pop(st);        //func para desempilha
            while (x != '(')
            {
                posfixo[j++] = x;
                x = stack_pop(st);     //func para desempilha
            }
            stack_push(st, x);        //func para empilha
            stack_push(st, inf[i]);   //func para empilha
            break;
        case '*':
        case '/':
            x = stack_pop(st);        //func para desempilha
            while (x != '(' && x != '+' && x != '-')
            {
                posfixo[j++] = x;
                x = stack_pop(st);     //func para desempilha
            }
            stack_push(st, x);        //func para empilha
            stack_push(st, inf[i]);   //func para empilha
            break;
        default:
            posfixo[j++] = inf[i];
        }
    }
    posfixo[j] = '\0';
    return posfixo;
    return 0;
}

