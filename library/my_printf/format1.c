/*
** EPITECH PROJECT, 2023
** forma
** File description:
** aaaaaa
*/
#include <stdarg.h>
#include <unistd.h>
#include "../../include/lib.h"
#include "my_printf.h"


int put_flag_d_and_i(va_list list)
{
    return (my_putnbr(va_arg(list, int)));
}

int put_flag_u(va_list list)
{
    return (my_putnbr(va_arg(list, unsigned int)));
}

int put_flag_o(va_list list)
{
    return (octal(va_arg(list, int)));
}

int put_flag_hexa(va_list list)
{
    return (hexa_1(va_arg(list, int)));
}

int put_flag_x(va_list list)
{
    return (hexa_2(va_arg(list, int)));
}
