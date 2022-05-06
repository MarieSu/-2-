#ifndef list_h
#define list_h

struct list
{
    int k;
    struct list *next;
};

void push(struct list *l, int k);

struct list *create(struct list *l, int n);

int find(struct list *l, int n, int r);

struct list *delete(struct list *l, int n);

short int empty(struct list *l);

void output(struct list *l);

#endif
