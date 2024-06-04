/*
** EPITECH PROJECT, 2024
** personal getline
** File description:
** get a line in a file descriptor
*/
#include <unistd.h>
#include "../strlib/strlib.h"
#include <stdio.h>

char *my_getline(int fd)
{
    char *line = NULL;
    char buffer[1];

    if (fd < 0)
        return NULL;
    while (read(fd, buffer, 1)) {
        if (buffer[0] == '\n')
            break;
        line = my_strappend(line, buffer[0]);
    }
    line = my_strappend(line, '\0');
    return line;
}
