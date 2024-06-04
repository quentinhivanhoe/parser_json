/*
** EPITECH PROJECT, 2024
** power function
** File description:
** power_func
*/

int power_func(int nb, int pwr)
{
    int n = nb;

    if (pwr == 0)
        return 1;
    for (int i = 1; i < pwr; i++)
        n *= nb;
    return n;
}
