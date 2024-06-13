/*
** EPITECH PROJECT, 2024
** personnal strcmp
** File description:
** compare two strings
*/

#include "../include/json.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

static int sensitive_case(char *s1, char *s2)
{
    char *tmp1 = NULL;
    char *tmp2 = NULL;
    int res = 0;

    if (!s1)
        return __INT_MAX__;
    if (!s2)
        return -__INT_MAX__;
    tmp1 = my_str_upper(s1);
    tmp2 = my_str_upper(s2);
    res = my_strcmp(tmp1, tmp2, false);
    free(tmp1);
    free(tmp2);
    return res;
}

int my_strcmp(char *s1, char *s2, bool sensitive)
{
    int len = 0;

    if (!s1)
        return __INT_MAX__;
    if (!s2)
        return -__INT_MAX__;
    if (sensitive)
        return sensitive_case(s1, s2);
    len = my_strlen(s1) - my_strlen(s2);
    if (len != 0)
        return len;
    for (int i = 0; s1[i] != '\0'; i++)
        if ((s1[i] - s2[i]) != 0)
            return s1[i] - s2[i];
    return 0;
}
