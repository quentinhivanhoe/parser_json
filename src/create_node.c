/*
** EPITECH PROJECT, 2024
** create_node
** File description:
** create a node of our json object
*/
#include "../include/json.h"
#include "../include/lib.h"
#include <stdio.h>

get_value_t get_value[] = {
    {INT, &get_int_value},
    {STR, &get_str_value},
    {BOOL, &get_bool_value},
    {ARRAY, &get_array_value},
    {JSON, &get_json_value},
    {ERROR, NULL},
};

json_t *init_node(json_t *prev, char *str)
{
    json_t *node = NULL;

    node = my_malloc(sizeof(json_t));
    node->type = get_value_type(str);
    node->prev = prev;
    if (node->type != STR)
        node->str_value = NULL;
    if (node->type != INT)
        node->int_value = 0;
    if (node->type != BOOL)
        node->bool_value = false;
    if (node->type != ARRAY)
        node->array_value = NULL;
    if (node->type != JSON)
        node->json_value = NULL;
    return node;
}

json_t *create_node(json_t *prev, char *str)
{
    json_t *node = NULL;

    if (!str || !(*str) || (*str) == '}')
        return NULL;
    if (str[0] == '{')
        str += 2;
    node = init_node(prev, str);
    for (unsigned int i = 0; get_value[i].get_func != NULL; i++)
        if (node->type == get_value[i].type)
            get_value[i].get_func(node, &str);
    node->next = create_node(node, str);
    return node;
}
