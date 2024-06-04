/*
** EPITECH PROJECT, 2024
** string to word array
** File description:
** transform a string into an array of string
*/
#include "strlib.h"
#include "../memlib/memlib.h"
#include <stddef.h>
#include <stdio.h>

int get_word_count(char *str, char tok)
{
    char *tmp = NULL;
    int nb_word = 0;

    tmp = my_strtok(str, tok);
    while (tmp) {
        nb_word++;
        tmp = my_strtok(NULL, tok);
    }
    return nb_word;
}

char **my_str_to_word_array(char *str, char delim)
{
    char **array = NULL;
    char *tmp = NULL;
    int nb_word = 0;

    if (!str)
        return NULL;
    nb_word = get_word_count(str, delim);
    printf("nb_word : [%i]\n", nb_word);
    array = my_malloc(sizeof(char *) * (nb_word + 1));
    tmp = my_strtok(str, delim);
    for (int i = 0; i < nb_word; i++) {
        array[i] = tmp;
        tmp = my_strtok(NULL, delim);
    }
    array[nb_word] = NULL;
    return array;
}
