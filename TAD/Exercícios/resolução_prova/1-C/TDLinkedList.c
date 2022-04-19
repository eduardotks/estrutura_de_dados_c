
// não entedi sua implementação - ela parece não ser do TAD da aula

int list_splice(List* dest, List* source, int pos) {

    if (pos == NULL) {
        dest = append(dest, source); // o que é append???

        free(source); // não é pra fazer isso
        return dest;
    }

    int found = 0;
    node *sp == NULL;
    for (sp = dest->first; sp != NULL; sp = sp->next) {
        if (sp == pos) { // compara inteiro com ponteiro

            node* aux = sp->next;
            sp->next = source->first;
            if (aux) {
                node* next->next = next->next;
                sp->next = source->last;
                sp->next->prev = dest->last;
                next->next = sp;

                free(source);
                return dest;
            }
            else {
                dest = append(dest, source);

                free(source);
                return dest;
            }
        }
    }

    return 0;
}
