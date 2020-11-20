/*
** EPITECH PROJECT, 2020
** lib_c
** File description:
** str.c
*/

#include "lib.h"

int strerr(char *str)
{
    for (size_t i = 0; str[i]; i++)
        write(2, &str[i], 1);
    return (84);
}

void print_str(char *str)
{
    for (size_t i = 0; str[i]; i++)
        write(1, &str[i], 1);
}

size_t str_len(char *str)
{
    size_t i = 0;

    for (; str[i]; i++);
    return (i);
}

char *my_calloc(size_t size)
{
    char *str = malloc(size);

    if (!str)
        exit(strerr("CALLOC FAILED\n"));
    for (size_t i = 0; i < size; i++)
        str[i] = '\0';
    return (str);
}

char *update_str(char *old, char buffer)
{
    size_t i = 0;

    if (old == NULL) {
        old = my_calloc(sizeof(char) * 2);
        old[0] = buffer;
        return (old);
    }
    char *new = my_calloc(sizeof(char) * (str_len(old) + 2));
    for (; old[i]; i++)
        new[i] = old[i];
    new[i] = buffer;
    free(old);
    return (new);
}