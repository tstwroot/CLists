#include <stdio.h>
#include "list.h"

int main()
{
    struct list *list = new_list();
    int a = 8;
    char b = 'A';

    append(list, (void*)&a, INT);
    append(list, (void*)&b, CHAR);
    show_itens(list);
}