/*
** EPITECH PROJECT, 2024
** personnal memncopy
** File description:
** copy a block of memory into a another
*/
#include <stddef.h>

void my_memncpy(void *dest, void *src, unsigned int nbyte)
{
    char *cdest = (char *)dest;
    char *csrc = (char *)src;
    unsigned int i = 0;

    while (i < nbyte) {
        cdest[i] = csrc[i];
        i++;
    }
    cdest[i] = 0;
}