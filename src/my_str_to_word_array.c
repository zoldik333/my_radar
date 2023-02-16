/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-BSQ-theo.vermorel
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

char *my_strncpy(char *dest, char const *src, int n);

static int my_isalphanum(char c)
{
    if ((c >= 65 && c <= 90) ||
        (c >= 97 && c <= 122) ||
        (c >= 48 && c <= 57))
        return 1;
    return 0;
}

static int words_counters(char const *str)
{
    int i = 0;
    int count_words = 0;
    for (i; str[i] != '\0'; i++) {
        if (!my_isalphanum(str[i]) && my_isalphanum(str[i + 1])) {
            count_words++;
        }
    }
    if (my_isalphanum(str[0]))
        count_words++;
    return count_words;
}

static int shortten_str(char const *str, char **array)
{
    int i = 0;
    int j = 0;
    int size = 0;
    while (str != NULL && str[i]) {
        if (my_isalphanum(str[i]))
            size++;
        if (my_isalphanum(str[i]) && (!my_isalphanum(str[i + 1]))) {
            array[j] = malloc(sizeof(char) * (size + 1));
            my_strncpy(array[j], &str[i - size + 1], size);
            size = 0;
            j++;
        }
        i++;
    }
    return j;
}

char **my_str_to_word_array(char const *str)
{
    char **array;
    char *temp;
    int j = 0;
    array = malloc(sizeof(char *) * (words_counters(str) + 1));
    j = shortten_str(str, array);
    array[j] = NULL;
    return array;
}
