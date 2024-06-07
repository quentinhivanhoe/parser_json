/*
** EPITECH PROJECT, 2024
** get_value_type
** File description:
** get the type of the key value
*/
#include "../include/json.h"
#include "../library/strlib/strlib.h"

node_t get_value_type(char *str)
{
    int index = 0;

    if (!str)
        return ERROR;
    index = my_strstr(str, ":", true) + 1;
    if (index < 0)
        return ERROR;
    if (str[index] == '{')
        return JSON;
    if (str[index] == '[')
        return ARRAY;
    if (str[index] == '"')
        return STR;
    if (str[index] > 47 && str[index] < 58)
        return INT;
    return BOOL;
}
