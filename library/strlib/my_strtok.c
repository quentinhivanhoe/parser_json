/*
** EPITECH PROJECT, 2024
** personnal strtok
** File description:
** my_strtok
*/
#include <stddef.h>
#include "stdio.h"
#include "strlib.h"

char *my_strtok(char *str, char tok)
{
    static char *save_str = NULL;
    char *new_str = NULL;

    if (str != NULL)
        save_str = my_strdup(str);
    if (!str && !save_str)
        return NULL;
    while (*save_str == tok)
        save_str++;
    if (!*save_str)
        return NULL;
    new_str = my_strduptil(save_str, tok);
    save_str += my_strlen(new_str);
    return new_str;
}
