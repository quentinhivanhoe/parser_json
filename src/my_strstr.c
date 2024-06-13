/*
** EPITECH PROJECT, 2024
** personal str str
** File description:
** find a string into another one
*/
#include "../include/json.h"

int my_strstr(char *str, char *tok, bool sensitive)
{
    unsigned int len = 0;

    if (!str || !tok)
        return -1;
    len = my_strlen(tok);
    for (unsigned int i = 0; str[i]; i++) {
        if (!my_strncmp(str + i, tok, len, sensitive))
            return i;
    }
    return -1;
}
