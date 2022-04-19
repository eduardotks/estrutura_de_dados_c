int verifica(char *s)
{
    
    Stack *st;
    char c;
    stack_push(st, s[0]);
    stack_top(st, &c);
    if(c != '(' && c != '[')
    {
        printf("\nInv�lido");
        return 0;
    }

    for(int i = 1; i < strlen(s); i++)
    {
        switch(s[i])
        {
        case 40:// "(" parenteses aberto decimal code
            stack_push(st, s[i]);
            break;

        case 41:// ")" parenteses fechado decimal code
            stack_top(st, &c);
            if(c == 40)
            {
                stack_pop(st);
                break;
            }
            else
            {
                printf("\nInv�lido");// liberar a pilha
                return 0;
            }

        case 91:// "["  colchete aberto decimal code
            stack_push(st, s[i]);
            break;

        case 93:// "]" colchete fechado decimal code
            stack_top(st, &c);
            if(c == 91)
            {
                stack_pop(st);
                break;
            }
            else
            {
                printf("\nInv�lido");
                return 0;
            }

        default:
            printf("\nERRO!!!");
            break;
        }
    }


    return 1; //retorna 1 se v�lido

    // testar se vazia aqui e no resto do código
}
