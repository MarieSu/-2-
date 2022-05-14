#ifndef LIST_H
#define LIST_H

typedef struct list
{
    char data[25];
    struct list* next;
    struct list* pr;
} list;

list* new_list(char data[]);
list* new_element(char data[], list* next);
list* last_element(list* L);
int list_is_empty(list* L);
int list_len(list* L);
list* insert(list* L, int index, char data[]);
list* del_index(list* L, int index);
list* del_value(list* L, char val[]);
list* del_list(list* L);
list* repl(list *L, list *H, int n, int r);
int print_list(list* L);

#endif
