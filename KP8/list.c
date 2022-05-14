#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "string.h"

list* first = NULL;

list* new_list(char data[]) { // список

    struct list *p;
    list* new_L = (list*)malloc(sizeof(list));
    strcpy(new_L->data, data); // сохранение поля данных добавляемого узла
    first = new_L; // предыдущий узел указывает на создаваемый
    new_L->next = first; // созданный узел указывает на следующий элемент
    new_L->pr = p;// созданный узел указывает на предыдущий узел

    return new_L;
}

list* new_element(char data[], list* next) {//элементы

    struct list *p;
    list* new_El = (list*)malloc(sizeof(list));
    strcpy(new_El->data, data);
    new_El->next = next;
    new_El->pr = p;
    return new_El;
    
}

list* last_element(list* L) {// предыдущий

    while (L->next != first) L = L->next;
    return L;
}

int list_is_empty(list* L) {// пустата

    if (L == NULL) return 1;
    return 0;
}

int list_len(list* L) {//длина

    if (list_is_empty(L)) return 0;

    int len = 0;

    do {
        len++;
        L = L->next;
    } while(L != first);

    return len;
}

list* insert(list* L, int index, char data[]) {// заполнение списка

    if (list_is_empty(L)) return new_list(data);//создание списка

    if (!index) {
        list* new_El = new_element(data, first);
        list* last = last_element(L);
        last->next = new_El;
        first = new_El;
    }
    else if (index < list_len(L)) {

        int i;
        for (i = 0 ; i < index-1 ; i++ ) L = L->next;

        list* new_El = new_element(data,L->next);
        L->next = new_El;
    }
    else if (index == list_len(L)) {

        list* last = last_element(L);
        list* new_El = new_element(data, first);
        last->next = new_El;
    }

    return first;
}

list* del_index(list* L, int index) {// удаление по индексу

    if ((!index) && (list_len(L) == 1)) {

        free(L);
        first = NULL;
    }
    else if (!index) {

       list* last = last_element(L);
       last->next = L->next;
       first = last->next;
       free(L);
    }
    else if (index < list_len(L)) {

        int i;
        for (i = 0 ; i < index-1 ; i++ ) L = L->next;

        struct list *pr, *next;
        list* tmp = L->next;
  	pr = tmp->pr; // узел, предшествующий lst
  	next = tmp->next; // узел, следующий за lst
 	if (pr != NULL)
    		pr->next = tmp->next; // переставляем указатель
  	if (next != NULL)
    		next->pr = tmp->pr; // переставляем указатель
  	free(tmp); // освобождаем память удаляемого элемента
    }

    return first;
}

list* del_value(list* L, char val[]) {// удаление по значению

    int index = 0;
    int len = list_len(L);

    while (strcmp(L->data, val) != 0) {

        index++;
        L = L->next;
        if (index >= len) {
            printf("\nТакого значения в списке нет\n");
            return first;
        }
    }

    first = del_index(first, index);
    printf("\nСтрока успешно удалена\n");
    return first;
}

list* del_list(list* L) { //удаление всего листа

    if (!list_is_empty(L)) {

        list* tmp;

        while (L->next != first) {

            tmp = L->next;
            free(L);
            L = tmp;
        }

        free(L);
        first = NULL;
    }

    return NULL;
}

list* repl(list *L, list *H, int n, int r) {// сортировка 
    char pl[25];
    if (n == r)
    {
        strcpy(pl, (L->next)->data);
        strcpy((L->next)->data, (L->pr)->data);
        strcpy((L->pr)->data, pl);
        return H;
    }
    r++;
    repl(L->next, H, n, r);
}

int print_list(list* L) {// печать

    int i = 1;

    if (list_is_empty(L)) return 1;

    do {
        printf(" %s [%d]", L->data, i);
        i++;
        L = L->next;
    } while (L != first);

    printf("\n");
    return 0;
}
