/*
** EPITECH PROJECT, 2020
** lib_c
** File description:
** my_calloc.c
*/

#include "lib.h"

bool str_in_str(char *str, char *target)
{
    size_t j = 0;

    for (size_t i = 0; str[i]; i++) {
        if (str[i] == target[j])
            j++;
        if (!target[j])
            return (true);
    }
    return (false);
}
