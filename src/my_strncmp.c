/*
** EPITECH PROJECT, 2024
** personal strncmp
** File description:
** compare n bytes of two strings
*/
#include "../include/json.h"
#include <stddef.h>
#include <stdlib.h>

static int sensitive_case(char *s1, char *s2, int nbyte)
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
    res = my_strncmp(tmp1, tmp2, nbyte, false);
    free(tmp1);
    free(tmp2);
    return res;
}

int my_strncmp(char *s1, char *s2, int nbyte, bool sensitive)
{
    if (!s1)
        return __INT_MAX__;
    if (!s2)
        return -__INT_MAX__;
    if (sensitive)
        return sensitive_case(s1, s2, nbyte);
    if ((my_strlen(s1) < nbyte) || (my_strlen(s2) < nbyte))
        return my_strlen(s1) - my_strlen(s2);
    for (int i = 0; i < nbyte; i++)
        if ((s1[i] - s2[i]) != 0)
            return s1[i] - s2[i];
    return 0;
}
