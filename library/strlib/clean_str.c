/*
** EPITECH PROJECT, 2024
** clean_str
** File description:
** clean a string
*/
#include "strlib.h"
#include "../memlib/memlib.h"
#include <stddef.h>

int get_len_clean_str(char *str, char tok)
{
    int len = 0;

    if (!str)
        return 0;
    for (unsigned int i = 0; str[i]; i++)
        if (str[i] != tok)
            len++;
    return len;
}

char *clean_str(char *str, char delim)
{
    char *clean = NULL;
    int index = 0;
    int len = 0;

    if (!str)
        return NULL;
    len = get_len_clean_str(str, delim);
    if (len == 0)
        return NULL;
    clean = my_malloc(sizeof(char *) * (len + 1));
    if (clean == NULL)
        return NULL;
    for (unsigned int i = 0; str[i]; i++) {
        if (str[i] != delim) {
            clean[index] = str[i];
            index++;
        }
    }
    clean[len] = '\0';
    return clean;
}
