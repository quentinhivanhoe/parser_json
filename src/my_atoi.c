/*
** EPITECH PROJECT, 2024
** personal getnbr
** File description:
** transform a string into a number
*/

int my_atoi(char *str)
{
    int nbr = 0;
    int i = 0;
    int sign = 1;

    if (!str)
        return -__INT_MAX__;
    if (str[0] == '-') {
        i++;
        sign *= -1;
    }
    for (; str[i] != '\0'; i++)
        nbr = (nbr * 10) + (str[i] - '0');
    return nbr * sign;
}
