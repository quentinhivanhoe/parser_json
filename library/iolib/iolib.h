/*
** EPITECH PROJECT, 2024
** input/ouput library header
** File description:
** iolib
*/

#ifndef IOLIB_H_
    #define IOLIB_H_

/// @brief getline
/// @param fd file descriptor
/// @return line
char *my_getline(int fd);

/// @brief get the content of the file
/// @param pathname the path/name of the file
/// @return the content of the file
char *my_getfile(char *pathname);

#endif /* !IOLIB_H_ */
