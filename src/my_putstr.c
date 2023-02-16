/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday04-theo.vermorel
** File description:
** my_putstr.c
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int counter = 0;
    while (*(str + counter) != '\0') {
        my_putchar(*(str + counter));
        counter++;
    }
    return counter;
}
