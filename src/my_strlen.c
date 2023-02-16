/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday04-theo.vermorel
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int count = 0;
    while (*(str + count) != '\0') {
        count++;
    }
    return (count);
}
