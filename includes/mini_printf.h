/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-myls-theo.vermorel
** File description:
** mini_printf
*/

#ifndef MINI_PRINTF_H_
    #define MINI_PRINTF_H_
    #include <stdarg.h>
    #include <unistd.h>
    #include <stdlib.h>
    void my_putchar(char c);
    int my_put_nbr(long long int nb);
    int my_putstr(char const *str);
    char *my_strcpy(char *dest, char const *src);
    char *my_strncpy(char *dest, char const *src, int n);
    int my_strlen(char const *str);
    int mini_printf(const char *format, ...);
    void condition_to_print(const char *format, va_list string,
    int *m, int *count);
    void condition_to_print2(const char *format, va_list string,
    int *m, int *count);
#endif
