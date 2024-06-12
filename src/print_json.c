/*
** EPITECH PROJECT, 2024
** print_json
** File description:
** print json object
*/
#include "../include/json.h"
#include "../include/lib.h"

void print_type(node_t type)
{
    if (type == INT)
        my_printf("[INT]");
    if (type == STR)
        my_printf("[STR]");
    if (type == BOOL)
        my_printf("[BOOL]");
    if (type == ARRAY)
        my_printf("[ARRAY]");
    if (type == JSON)
        my_printf("[JSON]");
}

void print_info(json_t *json)
{
    json_t *save_ptr = NULL;

    if (!json)
        return;
    save_ptr = json;
    while (json) {
        for (int i = 0; i < (2 *(json->depth + 1)); i++)
            my_printf(" ");
        my_printf("[%s] : ", json->key);
        print_type(json->type);
        my_printf("\n");
        if (json->type == JSON)
            print_info(json->json_value);
        json = json->next;
    }
    json = save_ptr;
}
