#ifndef __LIST_H__
#define __LIST_H__

typedef enum types
{
    CHAR = 0,
    INT,
    FLOAT,
    DOUBLE,
    BOOL,
    STRING
}types;

struct list *new_list();
struct node *append(struct list *, void *, enum types);
void show_itens(struct list *);

#endif