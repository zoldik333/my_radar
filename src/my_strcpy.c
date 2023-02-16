/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday06-theo.vermorel
** File description:
** my_strcpy.c
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    for (i; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
