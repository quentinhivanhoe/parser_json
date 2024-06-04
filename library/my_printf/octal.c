/*
** EPITECH PROJECT, 2023
** octal
** File description:
** aaa
*/
#include "../../include/lib.h"
#include "my_printf.h"
#include <unistd.h>

int octal(int nb)
{
    int cmp = 0;
    char *o = "01234567";
    int temp = 0;

    if (nb < 8) {
        my_putchar(o[nb]);
        cmp = cmp + 1;
    } else {
        cmp = cmp + octal(nb / 8);
        temp = nb % 8;
        my_putchar(o[temp]);
        cmp = cmp + 1;
    }
    return cmp;
}
