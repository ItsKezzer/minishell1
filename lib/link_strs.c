/*
** EPITECH PROJECT, 2020
** lib_c
** File description:
** link_strs.c
*/

#include "lib.h"

char *link_strs(char *str1, char *str2)
{
    size_t i = 0;
    char *res = my_calloc(sizeof(char) * (str_len(str1) + str_len(str2) + 1));

    for (; str1[i] && str1[i] != '\n'; i++)
        res[i] = str1[i];
    for (size_t j = 0; str2[j] && str2[j] != '\n'; j++, i++)
        res[i] = str2[j];
    return (res);
}