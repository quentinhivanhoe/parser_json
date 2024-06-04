/*
** EPITECH PROJECT, 2024
** parer json
** File description:
** simple json parser in c
*/
#include "include/lib.h"

int main(void)
{
    char *str = my_getfile("simple.json");

    my_printf("[%s]\n", str);
    mem_handler(NULL, DUMP);
    return 0;
}
