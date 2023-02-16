/*
** EPITECH PROJECT, 2022
** delivery_day_3
** File description:
** my_put_nbr.c
*/

#include <stdio.h>

void my_putchar(char c);

static void is_neg(long long int *nb)
{
    my_putchar('-');
    *nb = - *nb;
}

static void too_big(long long int *nb)
{
    *nb = 223372036854775808;
    my_putchar('9');
}

int my_put_nbr(long long int nb)
{
    long int divider = 1;
    int count_nbr = 1;
    int count = 0;
    if (nb < 0) {
        is_neg(&nb); count++;
    }
    if (nb == -9223372036854775807 - 1) {
        too_big(&nb); count++;
    }
    while (divider <= nb / 10) {
        divider = divider * 10;
        count_nbr++;
    }
    for (int i = 0; i < count_nbr; i++) {
        my_putchar((nb / divider) % 10 + 48);
        divider = divider / 10;
        count++;
    }
    return count;
}
