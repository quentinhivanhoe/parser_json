/*
** EPITECH PROJECT, 2024
** my personnal math lib
** File description:
** math lib headers
*/

#ifndef MATHLIB_H_
    #define MATHLIB_H_

    /// @brief returns the absolute number of nb
    #define ABS(nb) (nb < 0) ? (-nb) : (nb)

/// @brief power function
/// @param nb the number
/// @param pwr the power
/// @return the number at the power
int power_func(int nb, int pwr);

/// @brief transform a string into a number
/// @param str the string to transform
/// @return the string into a number
int my_atoi(char *str);

/// @brief coutn the number of digit of an number
/// @param nbr the number or parse
/// @return the number of digit
int my_nbrlen(int nbr);

#endif /* !MATHLIB_H_ */
