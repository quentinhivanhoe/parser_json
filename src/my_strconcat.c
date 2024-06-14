/*
** EPITECH PROJECT, 2024
** str concat
** File description:
** concat two strings and return the new strings
*/
#include "../include/json.h"
#include <stddef.h>
#include <stdlib.h>

char *my_strconcat(char *s1, char *s2)
{
    int len = 0;
    char *concat = NULL;

    if (s1 == NULL && s2 == NULL)
        return NULL;
    len = my_strlen(s1) + my_strlen(s2);
    concat = malloc(sizeof(char *) * (len + 1));
    my_strcat(concat, s1, s2);
    return concat;
}
