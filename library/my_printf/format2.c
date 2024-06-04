/*
** EPITECH PROJECT, 2023
** forma
** File description:
** aaaaaa
*/
#include "../../include/lib.h"
#include "my_printf.h"
#include <stdarg.h>
#include <unistd.h>

int put_flag_c(va_list list)
{
    my_putchar(va_arg(list, int));
    return 1;
}

int put_flag_s(va_list list)
{
    return (my_putstr(va_arg(list, char *)));
}

int put_flag_p(va_list list)
{
    return (addresse(va_arg(list, char *)));
}
