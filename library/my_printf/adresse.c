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

int hexa_grand(unsigned long nb)
{
    int cmp = 0;
    char *h = "0123456789abcdef";
    int temp = 0;

    if (nb < 16) {
        my_putchar(h[nb]);
        cmp = cmp + 1;
    } else {
        cmp = cmp + hexa_grand(nb / 16);
        temp = nb % 16;
        my_putchar(h[temp]);
        cmp = cmp + 1;
    }
    return cmp;
}

int addresse(char *i)
{
    int cmp = 0;

    my_putstr("0x");
    cmp = hexa_grand((unsigned long) i);
    return cmp;
}
