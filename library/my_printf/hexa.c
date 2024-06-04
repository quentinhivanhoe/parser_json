/*
** EPITECH PROJECT, 2023
** nombre to hexa
** File description:
** aaaaaa
*/
#include "../../include/lib.h"
#include "my_printf.h"
#include <unistd.h>
#include <stdarg.h>

int hexa_1(int nb)
{
    int cmp = 0;
    char *h = "0123456789ABCDEF";
    int temp = 0;

    if (nb < 16) {
        my_putchar(h[nb]);
        cmp = cmp + 1;
    } else {
        cmp = cmp + hexa_1(nb / 16);
        temp = nb % 16;
        my_putchar(h[temp]);
        cmp = cmp + 1;
    }
    return cmp;
}

int hexa_2(int nb)
{
    int cmp = 0;
    char *h = "0123456789abcdef";
    int temp = 0;

    if (nb < 16) {
        my_putchar(h[nb]);
        cmp = cmp + 1;
    } else {
        cmp = cmp + hexa_2(nb / 16);
        temp = nb % 16;
        my_putchar(h[temp]);
        cmp = cmp + 1;
    }
    return cmp;
}
