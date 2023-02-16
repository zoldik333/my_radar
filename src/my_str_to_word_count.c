/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-theo.vermorel
** File description:
** my_str_to_word_count
*/

#include <stdlib.h>

static int my_isalphanum(char c)
{
    if ((c >= 65 && c <= 90) ||
        (c >= 97 && c <= 122) ||
        (c >= 48 && c <= 57))
        return 1;
    return 0;
}

int my_str_to_word_count(char const *str)
{
    int i = 0;
    int j = 0;
    int size = 0;
    while (str != NULL && str[i]) {
        if (my_isalphanum(str[i]) && (!my_isalphanum(str[i + 1]))) {
            j++;
        }
        i++;
        if (str[i] == '/')
            return j;
    }
    return j;
}
