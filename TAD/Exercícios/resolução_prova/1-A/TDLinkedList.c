

int list_erase_even(List *li)
{
   //verifica��o
    if (li == NULL)
    {
        return -1;
    }
    else
    {
        DLNode *a;
        a = li->begin;//armazena endere�o de begin
        while (a != NULL)
        {
            li->begin = a->next;
            if(a->data % 2 == 0)
            {
                list_pop_back(li); // pq o pop back??
                free(a);
                a = li->begin;
            }

        }
        return 0;
    }

}
