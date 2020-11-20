/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** str to word
*/

#include "lib.h"

int total_words(char const *str)
{
    int tw = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] != '\0' || str[i] != ':')
            tw++;
    }
    return (tw);
}

int word_size(char const *str, int i)
{
    int wc = 0;

    for (; str[i] != ' ' && str[i] != '\n' && str[i] != '\0' && str[i] != ':';\
    i++, wc++);
    return (wc);
}

char **str_to_word_array(char const *str)
{
    int cword = 0;
    char **words = malloc(sizeof(char *) * (total_words(str) + 1));

    for (int i = 0; str[i] != '\0'; i++, cword++) {
        words[cword] = my_calloc(sizeof(char) * (word_size(str, i) + 1));
        for (int j = 0; str[i] != ' ' && str[i] != '\n' &&
        str[i] != '\0' && str[i] != ':'; i++, j++) {
            words[cword][j] = str[i];
        }
        if (!str[i]) {
            cword++;
            break;
        }
    }
    words[cword] = NULL;
    return (words);
}