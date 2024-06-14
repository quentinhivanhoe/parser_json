/*
** EPITECH PROJECT, 2024
** free json
** File description:
** free the json object
*/
#include "../include/json.h"
#include <stdlib.h>
#include <stdio.h>

void free_array(array_t **array)
{
    for (unsigned int i = 0; array[i]; i++) {
        if (array[i]->type == STR)
            free(array[i]->str_value);
        free(array[i]);
    }
    free(array);
}

void free_json(json_t *json)
{
    while (json) {
        free(json->key);
        if (json->prev && (json->depth == json->prev->depth))
            free(json->prev);
        if (json->type == STR)
            free(json->str_value);
        if (json->type == ARRAY)
            free_array(json->array_value);
        if (json->type == JSON)
            free_json(json->json_value);
        if (!json->next) {
            free(json);
            break;
        }
        json = json->next;
    }
}
