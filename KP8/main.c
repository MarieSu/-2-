#include <stdio.h>
#include <stdlib.h>
#include "list.h"
void menu(){
    printf("Вариант 18\n");
    printf("Тип элемента списка: строковый\n");
    printf("Вид списка: кольцевой двунаправленный\n");
    printf("Нестандартное действие: обменять местами (𝑘 − 1 )-й и (𝑘 + 1)-й элементы списка (𝑘 задаётся в качестве параметра)\n");
    printf("\n 1 - Добавить строку по номеру элемента\n");
    printf(" 2 - Удалить строку по номеру\n");
    printf(" 3 - Удалить строку по значению\n");
    printf(" 4 - Длина списка\n");
    printf(" 5 - Печать списка\n");
    printf(" 6 - Попарный обмен значений списка(задание)\n");
    printf(" 7 - Удалить список\n");
    printf(" 8 - Очистить экран\n");
    printf(" 9 - Выход\n");
}

int main(){
    int Key, val, n;
    char data[25];
    list* L = NULL;
    list* t;
    menu();
    while (1) {
        printf("\nВыберите действие: ");
        scanf("\n%d", &Key);
        switch(Key) {
            case 1:

                printf("\nВведите номер и значение: ");
                scanf("\n%d %s", &val, data);
                val--;

                if (val > list_len(L)) {
                    printf("\nНеправильный номер\n"); break;
                    }

                L = insert(L, val, data);
                break;

            case 2:

                if(list_is_empty(L)) {
                    printf("\nСписок пуст\n");
                    break;
                }
                printf("\nВведите номер: ");
                scanf("%d", &val);
                val--;

                if (val >= list_len(L)) {
                    printf("\nНеправильный номер\n");
                    break;
                }
                    
                L = del_index(L,val);
                break;

            case 3:

                if(list_is_empty(L)) {
                    printf("\nСписок пуст\n");
                    break;
                }
                printf("\nВведите значение: ");
                scanf("\n%s", data);
                L = del_value(L,data);
                break;

            case 4:

                printf("\nДлина списка: %d\n", list_len(L));
                break;

            case 5:
            
                if (print_list(L)) printf("\nСписок пуст\n");
                break;

            case 6:
            	printf("\nВведите значение k, относительно которого будет замена: ");
                scanf("%d", &n);
            	int l = list_len(L);
            	if ((n > l)||(n <= 0)||(l < 3))
                	printf(":-(\n");
            	else
            	{
              	  L = repl(L, L, n, 1);
           	 }
                break;

            case 7:
                if(list_is_empty(L)) {
                    printf("\nСписок уже пуст\n");
                    break;
                }
                L = del_list(L);
                break;

            case 8:

                system("clear");
                menu();
                break;

            case 9:

                printf("\n");
                return 0;
                break;

            default:

                printf("Такое действие отсутствует! \n");
                break;
         }
    }
    return 0;
}
