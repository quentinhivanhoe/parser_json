/*
** EPITECH PROJECT, 2024
** print value
** File description:
** print value of the json object
*/
#include "../include/json.h"
#include "../include/lib.h"

void print_bool(bool value)
{
    if (value)
        my_printf("true");
    else
        my_printf("false");
}

void print_array(array_t **array, int depth)
{
    my_printf("[\n");
    for (unsigned int i = 0; array[i]; i++) {
        for (int i = 0; i < (2 * (depth + 2)); i++)
            my_printf(" ");
        if (array[i]->type == STR)
            my_printf("\"%s\"", array[i]->str_value);
        if (array[i]->type == INT)
            my_printf("%i", array[i]->int_value);
        if (array[i]->type == BOOL)
            print_bool(array[i]->bool_value);
        if (array[i + 1])
            my_printf(",");
        my_printf("\n");
    }
    for (int i = 0; i < (2 * (depth + 1)); i++)
        my_printf(" ");
    my_printf("]");
}

void print_value(json_t *json)
{
    if (json->type == INT)
        my_printf("%d", json->int_value);
    if (json->type == STR)
        my_printf("\"%s\"", json->str_value);
    if (json->type == BOOL)
        print_bool(json->bool_value);
    if (json->type == ARRAY)
        print_array(json->array_value, json->depth);
    if (json->type == JSON)
        print_json(json->json_value);
    if (json->next)
        my_printf(",");
    my_printf("\n");
}
