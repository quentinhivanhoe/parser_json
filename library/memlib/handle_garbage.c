/*
** EPITECH PROJECT, 2024
** handle garbage
** File description:
** handle_garbage
*/
#include "memlib.h"
#include "../../include/lib.h"
#include <stdio.h>

void print_garbage(garbage_t *grb)
{
    garbage_t *save_grb = grb;
    unsigned int len = 0;

    while (grb != NULL) {
        len = my_memlen(grb->data);
        my_printf("Block allocated at: %p\n", grb->data);
        my_printf("Block lenght: %d\n", len);
        my_printf("-----------------------------------\n");
        grb = grb->next;
    }
    grb = save_grb;
    return;
}

void store_in_grabage(garbage_t **grb, void *data)
{
    garbage_t *new_grb = malloc(sizeof(garbage_t));

    new_grb->data = data;
    new_grb->next = (*grb);
    (*grb) = new_grb;
}

garbage_t *tmp_func(garbage_t **grb, void *data)
{
    garbage_t *del_grb = NULL;

    if (!(*grb)->next) {
        free((*grb)->data);
        free((*grb));
        return NULL;
    } else if ((*grb)->next->data == data) {
        del_grb = (*grb)->next;
        (*grb)->next = (*grb)->next->next;
        free(del_grb->data);
        free(del_grb);
        return (*grb);
    }
    return (*grb);
}

void del_in_garbage(garbage_t **grb, void *data)
{
    garbage_t *start = (*grb);

    while ((*grb) != NULL) {
        (*grb) = tmp_func(grb, data);
        if (!(*grb))
            break;
        (*grb) = (*grb)->next;
    }
    (*grb) = start;
    return;
}

void free_garbage(garbage_t *grb)
{
    void *saveptr = NULL;

    while (grb != NULL) {
        saveptr = grb;
        free(grb->data);
        grb = grb->next;
        free(saveptr);
    }
}
