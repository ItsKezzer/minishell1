/*
** EPITECH PROJECT, 2020
** lib_c
** File description:
** nbr.c
*/

#include "lib.h"

int get_nbr(char const *str)
{
    int res = 0;
    size_t neg = 0;

    for (size_t i = 0; str[i]; i++) {
        if (str[i] == '-') {
            neg++;
            continue;
        } else if (str[i] < '0' || str[i] > '9')
            break;
        else {
            res = (res + (str[i] - '0')) * 10;
        }
    }
    res /= 10;
    if (neg % 2 != 0)
        return (-res);
    return (res);
}

void print_nbr(int nbr)
{
    int a = 1;
    char buffer = '\0';

    if (nbr == 0)
        write(1, "0", 1);
    if (nbr < 0) {
        write(1, "-", 1);
        nbr = -nbr;
    }
    for (; nbr / a > 0; a *= 10);
    a /= 10;
    for (; a > 0; a /= 10) {
        buffer = nbr / a % 10 + 48;
        write(1, &buffer, 1);
    }
}