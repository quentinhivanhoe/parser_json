/*
** EPITECH PROJECT, 2024
** str_select
** File description:
** copy a part of a string
*/
#include <stddef.h>
#include "strlib.h"
#include <stdio.h>

char *str_select(char *str, char start, char end)
{
    char *select = NULL;
    unsigned int index = 0;

    if (!str)
        return NULL;
    if (my_strocc(str, start))
        for (; str[index] != start; index++);
    if (!my_strocc(str, end))
        end = '\0';
    select = my_strduptil(str + (index + 1), end);
    return select;
}
