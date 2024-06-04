/*
** EPITECH PROJECT, 2023
** flag e
** File description:
** flag e
*/

#include <stdio.h>
#include "../../include/lib.h"
#include "my_printf.h"

int zero_case_upper(void)
{
    my_putstr("0.000000E+00");
    return 12;
}

int exp_pos_upper(double nb)
{
    int exp = 0;

    if (nb < 0)
        nb = -nb;
    while (nb >= 10) {
        nb = nb / 10;
        exp = exp + 1;
    }
    flag_f(nb);
    my_putstr("E+");
    my_putnbr(exp / 10);
    my_putnbr(exp % 10);
    return 12;
}

int exp_neg_upper(double nb)
{
    int exp = 0;

    if (nb < 0)
        nb = -nb;
    while (nb < 1) {
        nb = nb * 10;
        exp = exp + 1;
    }
    flag_f(nb);
    my_putstr("E-");
    my_putnbr(exp / 10);
    my_putnbr(exp % 10);
    return 12;
}

int flag_e_upper(double nb)
{
    int cmp = 0;

    if (nb < 0)
        cmp = cmp + my_putchar('-');
    if (nb == 0)
        return zero_case_upper();
    if (nb >= 1 || nb <= -1)
        cmp = cmp + exp_pos_upper(nb);
    else
        cmp = cmp + exp_neg_upper(nb);
    return cmp;
}
