#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#include "TStack.h"
char *infixaParaPosfixa (Stack *pilha, char string[]);

int main()
{
    //***************************************************
    setlocale(LC_ALL, "Portuguese");
    //***************************************************

    //inserindo expressão de teste
    //char inf[100] = {"(5 *(((9 +8 )*(4 *6 ))+7 ))"};

    //***************************************************



   //eval
    Stack *pilha = stack_create(100);
    char array[20];
    printf("\nDigite a String: ");
    gets(array);


    //posfix
    char *posfixo;
    posfixo = infixaParaPosfixa (pilha, array);
    printf("\n\nForma postfix: %s", posfixo);



    printf("\n\nResultado: %d\n\n", calc_posfix(pilha, array));

    return 0;
}



char *infixaParaPosfixa (Stack *pilha, char string[]){
    int n = strlen(string);
    char *posf;
    posf = malloc ((n+1) * sizeof (char));
    int qtdposf = 0;

    for(int i = 0; i < n; i++){
        char aux = string[i];
        char x;
        switch(aux){
            case '(':
                stack_push(pilha, aux);
                break;
            case ')':
                stack_top(pilha, &x);
                stack_pop(pilha);
                while(x != '('){
                    posf[qtdposf++] = x;
                    stack_top(pilha, &x);
                    stack_pop(pilha);
                }
                break;
            case '-':
            case '+':
                stack_top(pilha, &x);
                stack_pop(pilha);
                while(x != '('){
                    posf[qtdposf++] = x;
                    stack_top(pilha, &x);
                    stack_pop(pilha);
                }
                stack_push(pilha, x);
                stack_push(pilha, aux);
                break;
            case '*':
            case '/':
                stack_top(pilha, &x);
                stack_pop(pilha);
                while(x != '(' && x != '+' && x != '-'){
                    posf[qtdposf++] = x;
                    stack_top(pilha, &x);
                    stack_pop(pilha);
                }
                stack_push(pilha, x);
                stack_push(pilha, aux);
                break;
            default:
                posf[qtdposf++] = aux;
        }

    }
    posf[qtdposf++] = '\0';
   return posf;
}



int calc_posfix(Stack *stack, char posfix[]){
    int i = 0;
    for(i = 0; i<strlen(posfix); i++){
        if(posfix[i] == ' ') continue;

        if(isdigit(posfix[i])){
            int num = 0;
            while(isdigit(posfix[i])){
                num=num*10 + (int)(posfix[i]-'0');
                i++;
            }
            i--;

            stack_push(stack, num);
        } else {

            float val1;
            stack_top(stack, &val1);
            stack_pop(stack);

            float val2;
            stack_top(stack, &val2);
            stack_pop(stack);

            switch (posfix[i]){
            case '+':
                stack_push(stack, val2 + val1);
                break;
                case '-': stack_push(stack, val2 - val1); break;
                case '*': stack_push(stack, val2 * val1); break;
                case '/': stack_push(stack, val2 / val1); break;
            }
        }
    }

    char retorno;
    stack_top(stack, &retorno);
    stack_pop(stack);
    return retorno;
}

