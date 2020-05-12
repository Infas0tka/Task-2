#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int i;

void print(list* L)
{
    node* rn = *L;
    while (rn)
    {
        printf("%d -> ", rn->value);
        rn = rn->next;
    }
    printf("NULL\n");
}

void push(list* L, int x)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = x;
    new_node->next = (*L);
    (*L) = new_node;
}

void push_b4(list* L, int n, int x)
{
    int k = 0;
    node* rn = *L;
    while(rn)
    {
        k += 1;
        if (rn->value == n)
            break;
        else rn = rn->next;
    }
    if (k == 1)
    {
        push(L, x);
        return;
    }
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = x;
    rn = *L;
    for (i = 1; i < k - 1; i++)
        rn = rn->next;
    new_node->next = rn->next;
    rn->next = new_node;
}

void push_after(list* L, int n, int x)
{
    int k = 0;
    node* rn = *L;
    while(rn)
    {
        k += 1;
        if (rn->value == n)
            break;
        else rn = rn->next;
    }
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = x;
    rn = *L;
    for (i = 1; i < k; i++)
        rn = rn->next;
    new_node->next = rn->next;
    rn->next = new_node;
}

void push_end(list* L, int x)
{
    if ((*L) == NULL)
    {
        push(L, x);
        return;
    }
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = x;
    node* rn = *L;
    while (rn->next != NULL)
        rn = rn->next;
    new_node->next = rn->next;
    rn->next = new_node;
}

int pop(list* L)
{
    int result = (*L)->value;
    node* second = (*L)->next;
    free(*L);
    *L = second;
    return result;
}

int pop_end(list* L)
{
    if ((*L)->next == NULL)
        return pop(L);
    node* rn = *L;
    while (rn->next->next != NULL)
        rn = rn->next;
    int result = rn->next->value;
    node* t = rn->next;
    rn->next = rn->next->next;
    free(t);
    return result;
}

int pop_num(list* L, int n)
{
    int k = 0;
    node* rn = *L;
    while(rn)
    {
        k += 1;
        if (rn->value == n)
            break;
        else rn = rn->next;
    }
    if (k == 1)
        return pop(L);
    rn = *L;
    for (i = 1; i < k - 1; i++)
        rn = rn->next;
    int results = rn->next->value;
    node* t = rn->next;
    rn->next = rn->next->next;
    free(t);
    return results;
}

void menu()
{
    setlocale(LC_ALL,"Rus");
    const char* menu = "1: Добавить в начало.\n"
                       "2: Распечатать.\n"
                       "3: Добавить перед.\n"
                       "4: Добавить после.\n"
                       "5: Добавить в конец.\n"
                       "6: Удалить первый.\n"
                       "7: Удалить последний.\n"
                       "8: Удалить определённый.\n"
                       "9: Сортировка элементов, стоящих на чётных местах.\n"
                       ;
    printf("%s\n", menu);
}

void upor(list* L)
{
    int j, t;
    int k = 1;
    node* rn = *L;
    while (rn->next)
    {
        k += 1;
        rn = rn->next;
    }
    for (i = 1; i < k / 2; i++)
    {
        rn = *L;
        rn = rn->next;
        for (j = 0; j < (k / 2) - i; j++)
        {
            if (rn->value > rn->next->next->value)
            {
                t = rn->value;
                rn->value = rn->next->next->value;
                rn->next->next->value = t;
            }
            rn = rn->next->next;
        }
    }
}
