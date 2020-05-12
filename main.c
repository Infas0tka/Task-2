#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Rus");
    int x, y, i;
    list L = NULL;
    menu();
    for(i = 0; i < 7; i++)
        push(&L, i*10 + rand() % 10 + 1);
    while (1)
        {
        int action;
        scanf("%d", &action);
        switch (action)
        {
            case 0:
                return 0;
            case 1:
                scanf("%d", &x);
                push(&L, x);
                break;
            case 2:
                print(&L);
                break;
            case 3:
                printf("Сначала перед кем добавить, потом кого.\n");
                scanf("%d %d", &x, &y);
                push_b4(&L, x, y);
                break;
            case 4:
                printf("Сначала после кого добавить, потом кого.\n");
                scanf("%d %d", &x, &y);
                push_after(&L, x, y);
                break;
            case 5:
                scanf("%d", &x);
                push_end(&L, x);
                break;
            case 6:
                pop(&L);
                break;
            case 7:
                pop_end(&L);
                break;
            case 8:
                scanf("%d", &x);
                pop_num(&L, x);
                break;
            case 9:
                upor(&L);
                break;
    return 0;
        }
        }
}



