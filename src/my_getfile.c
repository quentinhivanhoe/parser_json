/*
** EPITECH PROJECT, 2024
** my_getfile
** File description:
** get the content of the file
*/

#include "../include/json.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *my_getfile(char *pathname)
{
    char *content = "";
    int fd = 0;
    char buffer[BUFFER_SIZE];
    int size = 0;

    if (!pathname)
        return NULL;
    fd = open(pathname, O_RDONLY);
    if (fd < 0)
        return NULL;
    size = read(fd, buffer, BUFFER_SIZE);
    while (size) {
        buffer[size] = '\0';
        content = my_strconcat(content, buffer);
        size = read(fd, buffer, BUFFER_SIZE);
    }
    close(fd);
    return content;
}
