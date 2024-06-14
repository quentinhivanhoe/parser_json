/*
** EPITECH PROJECT, 2024
** create_node
** File description:
** create a node of our json object
*/
#include "../include/json.h"
#include <stdlib.h>
#include <stdio.h>

get_value_t get_value[] = {
    {INT, &get_int_value},
    {STR, &get_str_value},
    {BOOL, &get_bool_value},
    {ARRAY, &get_array_value},
    {JSON, &get_json_value},
    {ERROR, NULL},
};

void init_value(json_t *node)
{
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
}

json_t *init_node(json_t *prev, char *str, int *depth)
{
    json_t *node = NULL;

    node = malloc(sizeof(json_t));
    node->type = get_value_type(str);
    node->prev = prev;
    node->depth = (*depth);
    (*depth) = (node->type == JSON) ? ((*depth) + 1) : ((*depth));
    init_value(node);
    return node;
}

json_t *create_node(json_t *prev, char *str)
{
    json_t *node = NULL;
    static int depth = 0;

    if (!str || !(*str) || (*str) == '}') {
        depth -= 1;
        return NULL;
    }
    if (str[0] == '{')
        str += 2;
    node = init_node(prev, str, &depth);
    for (unsigned int i = 0; get_value[i].get_func != NULL; i++)
        if (node->type == get_value[i].type)
            get_value[i].get_func(node, &str);
    node->next = create_node(node, str);
    return node;
}

json_t *create_json(char *pathname)
{
    char *content = NULL;
    char *clean_content = NULL;
    json_t *json = NULL;

    if (!pathname)
        return NULL;
    content = my_getfile(pathname);
    if (!content)
        return NULL;
    clean_content = clean_str(content, ' ');
    if (!clean_content)
        return NULL;
    json = create_node(json, clean_content);
    free(content);
    free(clean_content);
    return json;
}
