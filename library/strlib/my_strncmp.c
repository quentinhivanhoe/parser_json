/*
** EPITECH PROJECT, 2024
** personal strncmp
** File description:
** compare n bytes of two strings
*/
#include "strlib.h"
#include "stdbool.h"

int my_strncmp(char *s1, char *s2, int nbyte, bool sensitive)
{
    if (!s1)
        return __INT_MAX__;
    if (!s2)
        return -__INT_MAX__;
    if (!sensitive) {
        s1 = my_str_upper(s1);
        s2 = my_str_upper(s2);
    }
    if ((my_strlen(s1) < nbyte) || (my_strlen(s2) < nbyte))
        return my_strlen(s1) - my_strlen(s2);
    for (int i = 0; i < nbyte; i++)
        if ((s1[i] - s2[i]) != 0)
            return s1[i] - s2[i];
    return 0;
}
