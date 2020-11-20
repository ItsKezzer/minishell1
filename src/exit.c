/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** exit.c
*/

#include "my.h"

bool my_exit(core_t *core, char *in)
{
    ssize_t i = 0;
    char **cmd = str_to_word_array(in);

    if (str_in_str(in, "exit") == false)
        return false;
    else if (!in || (cmd[0][0] == 'e' && cmd[0][1] == 'x' && cmd[0][2] == 'i' && cmd[0][3] == 't' && cmd[0][4] == '\0')) {
        print_str("exit\n");
        if (cmd[1])
            core->exit = get_nbr(cmd[1]);
        for (; cmd[i]; i++);
        for (; i > 0; i--)
            free(cmd[i]);
        free(cmd);
        return true;
    }
    return false;
}