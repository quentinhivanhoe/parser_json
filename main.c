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
    char *str = my_getfile("simple.json");
    char **arr = my_str_to_word_array(str, '\n');

    for (unsigned int i = 0; arr[i]; i++)
        printf("[%s]\n", arr[i]);
    mem_handler(NULL, DUMP);
    return 0;
}
