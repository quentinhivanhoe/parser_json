/*
** EPITECH PROJECT, 2024
** get value
** File description:
** get the value of the key
*/
#include "../include/json.h"
#include "../include/lib.h"

json_t *get_int_value(json_t *node, char **str)
{
    char *value = NULL;
    int next = 0;

    if (!node || !(*str))
        return NULL;
    value = str_select((*str), ':', ',');
    next = my_strstr((*str), "\n", true);
    if (!value)
        value = str_select((*str), ':', '\n');
    if (!value)
        return NULL;
    node->int_value = my_atoi(value);
    (*str) += (next + 1);
    return node;
}

json_t *get_str_value(json_t *node, char **str)
{
    int next = 0;

    if (!node || !(*str))
        return NULL;
    next = my_strstr((*str), "\n", true);
    node->str_value = str_select((*str), ':', ',');
    if (!node->str_value)
        return NULL;
    (*str) += (next + 1);
    return node;
}

json_t *get_bool_value(json_t *node, char **str)
{
    char *value = NULL;
    int next = 0;

    if (!node || !(*str))
        return NULL;
    value = str_select((*str), ':', ',');
    next = my_strstr((*str), "\n", true);
    if (!my_strcmp(value, "true", true))
        node->bool_value = true;
    if (!my_strcmp(value, "false", true))
        node->bool_value = false;
    (*str) += (next + 1);
    return node;
}
