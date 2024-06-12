/*
** EPITECH PROJECT, 2024
** print_json
** File description:
** print json object
*/

#include "../include/json.h"
#include "../include/lib.h"

void print_key(json_t *json)
{
    json_t *save_ptr = NULL;

    if (!json)
        return;
    save_ptr = json;
    while (json) {
        for (int i = 0; i < (2 * (json->depth + 1)); i++)
            my_printf(" ");
        my_printf("key : \"%s\"\n", json->key);
        if (json->type == JSON)
            print_key(json->json_value);
        json = json->next;
    }
    json = save_ptr;
}
