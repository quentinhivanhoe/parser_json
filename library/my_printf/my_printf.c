/*
** EPITECH PROJECT, 2023
** aaaaaaaa
** File description:
** bbb
*/
#include <stdarg.h>
#include <unistd.h>
#include "../../include/lib.h"
#include "my_printf.h"


format_t tab[] = {
    {'i', &put_flag_d_and_i},
    {'d', &put_flag_d_and_i},
    {'u', &put_flag_u},
    {'o', &put_flag_o},
    {'x', &put_flag_x},
    {'X', &put_flag_hexa},
    {'s', &put_flag_s},
    {'c', &put_flag_c},
    {'p', &put_flag_p},
    {'e', &put_flag_e},
    {'E', &put_flag_upper_e},
    {'f', &put_flag_f},
    {'\0', NULL}
};

int formatnbr1(char c, va_list list)
{
    int cmp = 0;

    while (tab[cmp].c != '\0') {
        if (tab[cmp].c == c) {
            return tab[cmp].function(list);
        }
        cmp = cmp + 1;
    }
    return 0;
}

int flag_pourcent(const char *format, int cmp)
{
    if (format[cmp] == '%' && format[cmp + 1] == '%') {
        my_putchar('%');
        return 1;
    }
    return 0;
}

int display(const char *format, int *cmp, va_list list)
{
    int temp = 0;

    if (flag_pourcent(format, *cmp) == 1) {
        temp = 1;
        *cmp = *cmp + 2;
    } else {
        temp = formatnbr1(format[*cmp + 1], list);
        *cmp = *cmp + 2;
    }
    return temp;
}

int my_printf(const char *format, ...)
{
    va_list list;
    int cmp = 0;
    int temp = 0;

    va_start(list, format);
    while (format[cmp] != '\0') {
        if (format[cmp] == '%') {
            temp = temp + display(format, &cmp, list);
        } else {
            my_putchar(format[cmp]);
            temp = temp + 1;
            cmp = cmp + 1;
        }
    }
    va_end(list);
    return temp;
}
