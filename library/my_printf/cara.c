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

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}

int my_putstr(char const *str)
{
    int cmp = 0;

    if (str == NULL)
        return 84;
    while (str[cmp]) {
        my_putchar(str[cmp]);
        cmp = cmp + 1;
    }
    return (cmp);
}

int my_putnbr(int nb)
{
    int digit = my_nbrlen(nb);
    int div = power_func(10, my_nbrlen(nb) - 1);
    int cmp = 0;
    char num;

    while (digit > 0) {
        num = (nb / div) + 48;
        cmp += write(1, &num, 1);
        nb %= div;
        div /= 10;
        digit -= 1;
    }
    cmp += write(1, "\n", 1);
    return cmp;
}
