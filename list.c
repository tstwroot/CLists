#include <stdlib.h>
#include "list.h"
#include <stdio.h>

struct data 
{
    enum types __type;
    void *data;
};

struct node
{
    struct data *__data;
    int __index;
    struct node *__next, *__prev;
};

struct list
{
    int __size;
    struct node *__sindex;
};

struct list *new_list()
{
    struct list *new_list = calloc(1, sizeof(struct list));
    new_list->__size = 0;
    new_list->__sindex = NULL;
    return(new_list);
}

struct node *new_node(void *__data, types __type)
{
    if(__data == NULL)
    {
        return(NULL);
    }

    struct node *new_node = calloc(1, sizeof(struct node));
    new_node->__data = __data;
    new_node->__index = 0;
    new_node->__next = NULL;
    new_node->__prev = NULL;
    return(0);
}

struct node *append(struct list *list, void *__data, types __type)
{
    if(list == NULL)
    {
        return(NULL);
    }

    if(list->__sindex == NULL)
    {
        list->__sindex = new_node(__data, __type);
        if(list->__sindex != NULL)
        {
            list->__size++;
        }
        
        return(list->__sindex);
    }

    struct node *aux = list->__sindex;

    while(aux->__next != NULL)
    {
        aux = aux->__next; 
    }

    aux->__next = new_node(__data, __type);
    if(aux->__next != NULL)
    {
        aux->__next->__prev = aux;
        list->__size++;

        return(aux->__next);
    }

    return(NULL);
}

void show_itens(struct list *list)
{
    if(list == NULL)
    {
        return;
    }

    struct node *aux = list->__sindex;

    while(aux != NULL)
    {
        switch (aux->__data->__type)
        {
        case CHAR:
            printf("%c ", *(char*)(aux->__data->data));
            break;
        case INT:
            printf("%d ", *(int*)aux->__data->data);

        case FLOAT:
            printf("%.2f ", *(float*)aux->__data->data);

        case DOUBLE:
            printf("%.8lf ", *(double*)aux->__data->data);

        case BOOL:
            printf("%s ", (char*)(*(int*)aux->__data->data == 1 ? "true" : "false"));

        case STRING:
            printf("%s ", (char*)aux->__data->data);

        default:
            break;
        }
        
        aux = aux->__next;
    }
}