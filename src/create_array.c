/*
** EPITECH PROJECT, 2024
** create array
** File description:
** create an array object
*/
#include "../include/json.h"
#include <stdlib.h>
#include <stdio.h>

void array_is_str(char *value, array_t *array)
{
    array->str_value = str_select(value, '"', '"');
    array->int_value = 0;
    array->bool_value = 0;
}

void array_is_int(char *value, array_t *array)
{
    array->str_value = NULL;
    array->int_value = my_atoi(value);
    array->bool_value = 0;
}

void array_is_bool(char *value, array_t *array)
{
    array->str_value = NULL;
    array->int_value = 0;
    if (!my_strcmp(value, "true", true))
        array->bool_value = true;
    else
        array->bool_value = false;
}

void init_array_value(char *value, array_t *array)
{
    if (array->type == STR)
        array_is_str(value, array);
    else if (array->type == INT)
        array_is_int(value, array);
    else
        array_is_bool(value, array);
}

array_t *create_array(char **str)
{
    char *line = NULL;
    array_t *array = NULL;
    int next = 0;

    if (!(*str))
        return NULL;
    array = malloc(sizeof(array_t));
    if (my_strocc((*str), ','))
        line = my_strduptil((*str), ',');
    else
        line = my_strduptil((*str), '\n');
    next = (!my_strocc((*str), ',')) ? my_strlen(line) : my_strlen(line) + 2;
    array->type = get_value_type(line);
    init_array_value(line, array);
    (*str) += next;
    free(line);
    return array;
}
