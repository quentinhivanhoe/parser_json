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
    node->key = str_select((*str), '"', '"');
    next = my_strstr((*str), "\n", true);
    if (!my_strocc((*str), ','))
        value = str_select((*str), ':', '\n');
    else if (!value)
        value = str_select((*str), ':', ',');
    node->int_value = my_atoi(value);
    (*str) += (next + 1);
    return node;
}

json_t *get_str_value(json_t *node, char **str)
{
    int next = 0;
    char *value = NULL;

    if (!node || !(*str))
        return NULL;
    next = my_strstr((*str), "\n", true);
    node->key = str_select((*str), '"', '"');
    if (my_strocc((*str), ':') < 1)
        node->str_value = str_select((*str), '"', '"');
    else {
        value = str_select((*str), ':', '\n');
        node->str_value = str_select(value, '"', '"');
    }
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
    node->key = str_select((*str), '"', '"');
    if (!value)
        value = str_select((*str), ':', '\n');
    if (!value)
        return NULL;
    next = my_strstr((*str), "\n", true);
    if (!my_strcmp(value, "true", true))
        node->bool_value = true;
    if (!my_strcmp(value, "false", true))
        node->bool_value = false;
    (*str) += (next + 1);
    return node;
}

json_t *get_json_value(json_t *node, char **str)
{
    char *value = NULL;
    int next = 0;

    if (!node || !(*str))
        return NULL;
    node->key = str_select((*str), '"', '"');
    value = str_select((*str), '\n', '}');
    next = my_strstr((*str), "}", true);
    next = (next == -1) ? (my_strlen((*str))) : (next + 2);
    next = ((*str)[next] == '\n') ? (next + 1) : (next);
    node->json_value = create_node(node, value);
    (*str) += next;
    return node;
}

json_t *get_array_value(json_t *node, char **str)
{
    int nb_value = 0;
    char *value = NULL;
    int next = 0;

    if (!node || !(*str))
        return NULL;
    node->key = str_select((*str), '"', '"');
    value = str_select((*str), '\n', ']');
    nb_value = my_strocc(value, '\n');
    next = my_strstr((*str), "]", true) + 2;
    node->array_value = malloc(sizeof(array_t *) * (nb_value + 1));
    for (int i = 0; i < nb_value; i++)
        node->array_value[i] = create_array(&value, nb_value, i);
    node->array_value[nb_value] = NULL;
    next = ((*str)[next] == '\n') ? (next + 1) : (next);
    (*str) += next;
    return node;
}
