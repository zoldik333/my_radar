/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday07-sebastien.lucas
** File description:
** my_str_isnum.c
*/

int my_str_isnum(char const *str)
{
    if (str[0] == '\0') {
        return 1;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return 1;
    }
    return 0;
}
