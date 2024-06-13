/*
** EPITECH PROJECT, 2024
** parer json
** File description:
** simple json parser in c
*/
#include "include/json.h"
#include <stdio.h>

int main(int ac, char **av)
{
    char *str = my_getfile(av[1]);
    char *clean = clean_str(str, ' ');
    json_t *json = create_node(NULL, clean);

    print_info(json);
    printf("\n\n");
    print_json(json);
    return ac;
}
