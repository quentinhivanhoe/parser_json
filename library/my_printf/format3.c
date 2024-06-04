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

int put_flag_e(va_list list)
{
    return flag_e(va_arg(list, double));
}

int put_flag_upper_e(va_list list)
{
    return flag_e_upper(va_arg(list, double));
}

int put_flag_f(va_list list)
{
    return flag_f(va_arg(list, double));
}
