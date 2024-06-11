/*
** EPITECH PROJECT, 2024
** pretty_printer_test
** File description:
** print the json object
*/
#include "../include/json.h"
#include "../include/lib.h"
#include <stdio.h>

void array_printer(array_t **array)
{
    for (unsigned int i = 0; array[i]; i++) {
        if (array[i]->type == STR)
            printf("[%s]\n", array[i]->str_value);
        if (array[i]->type == INT)
            printf("[%i]\n", array[i]->int_value);
        if (array[i]->type == BOOL && array[i]->bool_value)
            printf("[True]\n");
        if (array[i]->type == BOOL && !array[i]->bool_value)
            printf("[False]\n");
    }
}

void pretty_printer_test(json_t *json)
{
    while (json) {
        if (json->type == STR)
            printf("[%s]\n", json->str_value);
        if (json->type == INT)
            printf("[%li]\n", json->int_value);
        if (json->type == BOOL && json->bool_value)
            printf("True\n");
        if (json->type == BOOL && !json->bool_value)
            printf("False\n");
        if (json->type == ARRAY)
            array_printer(json->array_value);
        if (json->type == JSON)
            pretty_printer_test(json->json_value);
        json = json->next;
    }
}
