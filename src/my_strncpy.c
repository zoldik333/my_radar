/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday07-sebastien.lucas
** File description:
** my_strncpy.c
*/

static int my_strlen10(const char *string)
{
    int taille = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        taille++;
    }
    return taille;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    for (i; i < n; i++) {
        dest[i] = src[i];
    }
    if (my_strlen10(src) < n) {
        dest[my_strlen10(src)] = '\0';
    }
    *(dest + i) = '\0';
    return dest;
}
