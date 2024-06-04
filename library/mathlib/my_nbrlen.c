/*
** EPITECH PROJECT, 2024
** number len
** File description:
** calcul the len (number of digit) of a number
*/
#include "mathlib.h"

int my_nbrlen(int nbr)
{
    int tmp = ABS(nbr);
    int cmp = 1;

    for (; tmp >= 10; cmp++)
        tmp /= 10;
    return cmp;
}
