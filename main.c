/*
** EPITECH PROJECT, 2024
** parer json
** File description:
** simple json parser in c
*/
#include "include/lib.h"
#include <stdio.h>

int main(void)
{
    char *str = my_getfile("toto.json");
    char *clean = clean_str(str, ' ');
    char *select = str_select(clean, '"', '"');

    printf("[%s]\n", select);
    mem_handler(NULL, DUMP);
    return 0;
}
