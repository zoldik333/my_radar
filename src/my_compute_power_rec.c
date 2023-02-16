/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday07-sebastien.lucas
** File description:
** my_compute_power_rec.c
*/

#include <stdio.h>

float my_compute_power_rec(float nb, float p)
{
    long result = 1;
    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    result = nb * (my_compute_power_rec(nb, p - 1));
    if (result < -2147483648 || result > 2147483647)
        return 0;
    return result;
}
