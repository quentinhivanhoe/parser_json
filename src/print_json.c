/*
** EPITECH PROJECT, 2024
** print_json
** File description:
** print json object
*/
#include "../include/json.h"
#include <stdio.h>

void print_type(node_t type)
{
    if (type == INT)
        printf("[INT]");
    if (type == STR)
        printf("[STR]");
    if (type == BOOL)
        printf("[BOOL]");
    if (type == ARRAY)
        printf("[ARRAY]");
    if (type == JSON)
        printf("[JSON]");
}

void print_info(json_t *json)
{
    json_t *save_ptr = NULL;

    if (!json)
        return;
    save_ptr = json;
    while (json) {
        for (int i = 0; i < (2 *(json->depth + 1)); i++)
            printf(" ");
        printf("[%s] : ", json->key);
        print_type(json->type);
        printf("\n");
        if (json->type == JSON)
            print_info(json->json_value);
        json = json->next;
    }
    json = save_ptr;
}

void print_json(json_t *json)
{
    json_t *save_ptr = NULL;

    if (!json)
        return;
    save_ptr = json;
    printf("{\n");
    while (json) {
        for (int i = 0; i < (2 *(json->depth + 1)); i++)
            printf(" ");
        printf("\"%s\" : ", json->key);
        print_value(json);
        json = json->next;
    }
    for (int i = 0; i < (2 * save_ptr->depth); i++)
        printf(" ");
    printf("}");
    json = save_ptr;
}
