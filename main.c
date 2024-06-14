/*
** EPITECH PROJECT, 2024
** parer json
** File description:
** simple json parser in c
*/
#include "include/json.h"
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    json_t *json = create_json(av[1]);

    print_info(json);
    free_json(json);
    return ac;
}
