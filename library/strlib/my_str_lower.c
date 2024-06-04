/*
** EPITECH PROJECT, 2024
** my str lower
** File description:
** turn an alphanumeric string into lowercase
*/
#include "strlib.h"
#include "../memlib/memlib.h"
#include <stddef.h>

char *my_str_lower(char *str)
{
    char *new_str = NULL;
    int len = 0;

    if (!str)
        return NULL;
    len = my_strlen(str);
    new_str = my_malloc(sizeof(char) * (len + 1));
    for (unsigned int i = 0; str[i]; i++) {
        if (IS_UPPER(str[i])) {
            new_str[i] = str[i] + 32;
            continue;
        }
        new_str[i] = str[i];
    }
    new_str[len] = '\0';
    return new_str;
}
