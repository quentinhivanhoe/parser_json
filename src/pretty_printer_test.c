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
    printf("[\n");
    for (unsigned int i = 0; array[i]; i++) {
        if (array[i]->type == STR)
            printf("\"%s\"", array[i]->str_value);
        if (array[i]->type == INT)
            printf("%i", array[i]->int_value);
        if (array[i]->type == BOOL && array[i]->bool_value)
            printf("True");
        if (array[i]->type == BOOL && !array[i]->bool_value)
            printf("False");
        if (array[i + 1] != NULL)
            printf(",");
        printf("\n");
    }
    printf("]");
}

void print_value(json_t *json)
{
    printf("\"%s\" : ", json->key);
    if (json->type == ARRAY)
        array_printer(json->array_value);
    if (json->type == STR)
        printf("\"%s\"", json->str_value);
    if (json->type == INT)
        printf("%li", json->int_value);
    if (json->type == BOOL && json->bool_value)
        printf("True");
    if (json->type == BOOL && !json->bool_value)
        printf("False");
    if (json->type == JSON)
        pretty_printer_test(json->json_value);
}

void pretty_printer_test(json_t *json)
{
    printf("{\n");
    while (json) {
        print_value(json);
        if (json->next)
            printf(",");
        printf("\n");
        json = json->next;
    }
    printf("}");
}
