/*
** EPITECH PROJECT, 2024
** str append
** File description:
** append a character at the end o a str
*/
#include "../include/json.h"
#include <stddef.h>
#include <stdlib.h>

char *my_strappend(char *str, char c)
{
    char *new_str = NULL;
    int len = 0;

    len = my_strlen(str);
    new_str = malloc(sizeof(char *) * (len + 2));
    my_strcpy(new_str, str);
    new_str[len] = c;
    new_str[len + 1] = '\0';
    return new_str;
}
