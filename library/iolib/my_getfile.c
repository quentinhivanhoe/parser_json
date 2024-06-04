/*
** EPITECH PROJECT, 2024
** my_getfile
** File description:
** get the content of the file
*/
#include "../../include/lib.h"
#include <fcntl.h>
#include <unistd.h>

char *my_getfile(char *pathname)
{
    char *content = NULL;
    int fd = 0;
    char buffer[1];

    if (!pathname)
        return NULL;
    fd = open(pathname, O_RDONLY);
    if (fd < 0)
        return NULL;
    while (read(fd, buffer, 1))
        content = my_strappend(content, buffer[0]);
    content = my_strappend(content, '\0');
    return content;
}
