/*
** EPITECH PROJECT, 2024
** print value
** File description:
** print value of the json object
*/
#include "../include/json.h"
#include <stdio.h>

void print_bool(bool value)
{
    if (value)
        printf("true");
    else
        printf("false");
}

void print_array(array_t **array, int depth)
{
    printf("[\n");
    for (unsigned int i = 0; array[i]; i++) {
        for (int i = 0; i < (2 * (depth + 2)); i++)
            printf(" ");
        if (array[i]->type == STR)
            printf("\"%s\"", array[i]->str_value);
        if (array[i]->type == INT)
            printf("%i", array[i]->int_value);
        if (array[i]->type == BOOL)
            print_bool(array[i]->bool_value);
        if (array[i + 1])
            printf(",");
        printf("\n");
    }
    for (int i = 0; i < (2 * (depth + 1)); i++)
        printf(" ");
    printf("]");
}

void print_value(json_t *json)
{
    if (json->type == INT)
        printf("%ld", json->int_value);
    if (json->type == STR)
        printf("\"%s\"", json->str_value);
    if (json->type == BOOL)
        print_bool(json->bool_value);
    if (json->type == ARRAY)
        print_array(json->array_value, json->depth);
    if (json->type == JSON)
        print_json(json->json_value);
    if (json->next)
        printf(",");
    printf("\n");
}
