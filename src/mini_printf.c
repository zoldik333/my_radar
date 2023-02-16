/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-miniprintf-theo.vermorel
** File description:
** mini_printf
*/

#include <stdarg.h>
#include "../includes/mini_printf.h"

void condition_to_print2(const char *format, va_list string, int *m, int *count)
{
    if (format[*m + 1] == 's') {
        *count += my_putstr(va_arg(string, char *));
        *m = *m + 2;
        return;
    }
    if (format[*m + 1] == '%') {
        my_putchar('%');
        *m = *m + 2;
        *count++;
        return;
    }
}

void condition_to_print(const char *format, va_list string, int *m, int *count)
{
    if (format[*m + 1] == 'd' || format[*m + 1] == 'i') {
        *count = *count + my_put_nbr(va_arg(string, long long int));
        *m = *m + 2;
        return;
    }
    if (format[*m + 1] == 'c') {
        my_putchar(va_arg(string, int));
        *m = *m + 2;
        *count++;
        return;
    }
}

int mini_printf(const char *format, ...)
{
    va_list string;
    va_start(string, format);
    int i = 0;
    int *j = &i;
    int count_parameters = 0;
    int *ptr = &count_parameters;
    while (format[i] != '\0') {
        if (format[i] == '%') {
            condition_to_print(format, string, j, ptr);
            condition_to_print2(format, string, j, ptr);
        } else {
            my_putchar(format[i]);
            i++;
            count_parameters++;
        }
    }
    va_end(string);
    return count_parameters;
}
