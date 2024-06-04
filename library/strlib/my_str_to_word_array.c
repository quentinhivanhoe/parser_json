/*
** EPITECH PROJECT, 2024
** string to word array
** File description:
** transform a string into an array of string
*/
#include "strlib.h"
#include "../memlib/memlib.h"
#include <stddef.h>
#include <stdio.h>

char **my_str_to_word_array(char *str, char delim)
{
    char **array = NULL;
    char *tmp = NULL;

    if (!str)
        return NULL;
    tmp = my_strtok(str, delim);
    for (unsigned int i = 0; tmp; i++) {
        array = my_realloc(array, sizeof(char *) * (i + 2));
        array[i] = tmp;
        array[i + 1] = NULL;
        tmp = my_strtok(NULL, delim);
    }
    return array;
}
