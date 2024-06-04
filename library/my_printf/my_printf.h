/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_
    #include <stdarg.h>

typedef struct format_s {
    char c; // 'i', 'd', 'u', etc.
    int (*function)(va_list);
} format_t;

int flag_f(double nb);
int flag_e(double nb);
int flag_e_upper(double nb);
int my_putchar(char c);
int my_putstr(char const *str);
int my_putnbr(int nb);
int octal(int nb);
int hexa_1(int nb);
int hexa_2(int nb);
int hexa_grand(unsigned long nb);
int addresse(char *i);
int my_printf(const char *format, ...);
int put_flag_d_and_i(va_list list);
int put_flag_u(va_list list);
int put_flag_o(va_list list);
int put_flag_x(va_list list);
int put_flag_hexa(va_list list);
int put_flag_c(va_list list);
int put_flag_s(va_list list);
int put_flag_p(va_list list);
int put_flag_e(va_list list);
int put_flag_upper_e(va_list list);
int put_flag_f(va_list list);

#endif /* !MY_PRINTF_H_ */
