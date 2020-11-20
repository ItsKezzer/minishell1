/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** clean_str.c
*/

#include "my.h"

bool alphanum_check(char **cmd)
{
    if (!((cmd[1][0] >= 'a' && cmd[1][0] <= 'z') || (cmd[1][0] >= 'A' &&\
    cmd[1][0] <= 'Z'))) {
        print_str("setenv: Variable name must begin with a letter.\n");
        return false;
    }
    for (size_t i = 0; cmd[i]; i++) {
        for (size_t j = 0; cmd[i][j] && cmd[i][j] != '\n'; j++) {
            if (!((cmd[i][j] >= '0' && cmd[i][j] <= '9') || (cmd[i][j] >= 'a'\
            && cmd[i][j] <= 'z') || (cmd[i][j] >= 'A' && cmd[i][j] <= 'Z') ||\
            (cmd[i][j] == ' ' || cmd[i][j] == '_'))) {
                print_str("setenv: Variable name must contain ");
                print_str("alphanumeric characters.\n");
                return false;
            }
        }
    }
    return true;
}

char *clean_str(char *str)
{
    char *buff = NULL;
    size_t j = 0;

    for (size_t i = 0; str[i]; i++) {
        if ((str[i] == ' ' || str[i] == '\t') && ((!buff || buff[j - 1] == ' ')\
        || (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0' || \
        str[i + 1] == '\n')))
            continue;
        if (str[i] == '\t')
            buff = update_str(buff, ' ');
        else
            buff = update_str(buff, str[i]);
        j++;
    }
    free(str);
    return buff;
}
