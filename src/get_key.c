/*
** EPITECH PROJECT, 2024
** get key
** File description:
** get the value of a key in the json
*/

#include "../include/json.h"
#include "../include/lib.h"

void copy_value(json_t *node, json_t *copy)
{
    if (node->type == STR)
        copy->str_value = node->str_value;
    if (node->type == INT)
        copy->int_value = node->int_value;
    if (node->type == BOOL)
        copy->bool_value = node->bool_value;
    if (node->type == ARRAY)
        copy->array_value = node->array_value;
    if (node->type == JSON)
        copy->json_value = node->json_value;
}

json_t *get_node(json_t *node)
{
    json_t *copy = NULL;

    if (!node)
        return NULL;
    copy = my_malloc(sizeof(json_t));
    copy->prev = NULL;
    copy->next = NULL;
    copy->depth = 0;
    copy->key = node->key;
    copy->type = node->type;
    init_value(copy);
    copy_value(node, copy);
    return copy;
}

json_t *get_key(json_t *json, char *path)
{
    char *key = NULL;
    int next = 0;

    if (!json || !path)
        return NULL;
    key = my_strduptil(path, ':');
    my_printf("key : [%s]\n", json->key);
    if (!my_strcmp(json->key, key, true)) {
        next = my_strstr(path, ":", true) + 1;
        if (!my_strocc(path, ':'))
            return get_node(json);
        else
            return get_key(json->json_value, path + next);
    }
    return get_key(json->next, path);
}
