/*
** EPITECH PROJECT, 2024
** parer json
** File description:
** simple json parser in c
*/
#include "include/lib.h"
#include "include/json.h"
#include <stdio.h>

int main(void)
{
    char *str = my_getfile("simple.json");
    char *clean = clean_str(str, ' ');
    json_t *json = create_node(NULL, clean);

    while (json) {
        if (json->type == STR)
            printf("[%s]\n", json->str_value);
        if (json->type == INT)
            printf("[%li]\n", json->int_value);
        if (json->type == BOOL && json->bool_value)
            printf("True\n");
        if (json->type == BOOL && !json->bool_value)
            printf("False\n");
        json = json->next;
    }
    mem_handler(NULL, DUMP);
    return 0;
}
