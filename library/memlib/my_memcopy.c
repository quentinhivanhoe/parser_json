/*
** EPITECH PROJECT, 2024
** personnal memcopy
** File description:
** copy a block of memory into a another
*/
#include <stddef.h>

void my_memcpy(void *dest, void *src)
{
    char *cdest = (char *)dest;
    char *csrc = (char *)src;
    unsigned int i = 0;

    while (csrc[i] != 0) {
        cdest[i] = csrc[i];
        i++;
    }
    cdest[i] = 0;
}
