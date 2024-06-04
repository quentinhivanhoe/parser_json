/*
** EPITECH PROJECT, 2023
** my_putfloat
** File description:
** put float
*/
#include "../../include/lib.h"
#include "my_printf.h"
#include <stdio.h>
#include <unistd.h>

int display_dec(double nb)
{
    int acr = power_func(10, 3);
    int nb_dec = 0;
    int i = 0;

    if (nb < 0)
        nb = -nb;
    nb_dec = nb * acr;
    if ((nb_dec % 10) > 5)
        nb_dec = nb_dec + 10;
    acr = acr / 10;
    while (i < 2) {
        my_putchar((nb_dec / acr) + 48);
        nb_dec = nb_dec % acr;
        acr = acr / 10;
        i = i + 1;
    }
    return 6;
}

int flag_f(double nb)
{
    int n = -nb;
    int cmp = 0;

    if (nb > 2147483647 || nb < -2147483647) {
        write(2, "ERROR\n", 6);
        return (-1);
    }
    if (n == 0 && nb < 0)
        cmp = cmp + my_putchar('-');
    cmp = cmp + my_putnbr(-n);
    cmp = cmp + my_putchar('.');
    cmp = cmp + display_dec(nb + n);
    return cmp;
}
