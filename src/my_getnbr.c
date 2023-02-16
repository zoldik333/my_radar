/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-BSQ-theo.vermorel
** File description:
** my_getnbr
*/

static int disp_nbr(int is_neg, long int number)
{
    if (is_neg % 2 == 0) {
        if (number >= 2147483648) {
            return 0;
        }
    } else {
        if (number > 2147483648) {
            return 0;
        }
        number = number * (-1);
        }
    return number;
}

static int manage_long(long int number, char const *str, int i, int is_neg)
{
    if (number * 10 + (str[i] - 48) >= 2147483648) {
            if (is_neg % 2 == 0)
                return 0;
    }
}

int my_getnbr(char const *str)
{
    int is_neg = 0;
    int i = 0;
    long number = 0;
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            is_neg++;
        }
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        if (!manage_long(number, str, i, is_neg))
            return 0;
        number = number * 10 + (str[i] - 48);
        if (number > 2147483648 || number < -2147483648)
            return 0;
        i++;
    }
    number = disp_nbr(is_neg, number);
    return number;
}
