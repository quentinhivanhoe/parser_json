/*
** EPITECH PROJECT, 2024
** create_node
** File description:
** create a node of our json object
*/
#include "../include/json.h"
#include "../include/lib.h"
#include <stdio.h>

json_t *create_node(json_t *prev, char *str)
{
    json_t *node = NULL;

    if (!str || !(*str) || (*str) == '}')
        return NULL;
    node = my_malloc(sizeof(json_t));
    if (str[0] == '{')
        str += 2;
    node->prev = prev;
    node->type = get_value_type(str);
    if (node->type == INT)
        get_int_value(node, &str);
    if (node->type == BOOL)
        get_bool_value(node, &str);
    if (node->type == STR)
        get_str_value(node, &str);
    if (node->type == ARRAY)
        get_array_value(node, &str);
    node->next = create_node(node, str);
    return node;
}
