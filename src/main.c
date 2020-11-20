/*
** EPITECH PROJECT, 2020
** minishell1_v2
** File description:
** main
*/

#include "my.h"

int main(int argc, char const *argv[], char **env)
{
    core_t core = {0};

    (void)argv;
    if (argc != 1)
        return (strerr("NO ARGUMENTS NEEDED\n"));
    core.env = env;
    core.home = getcwd(NULL, 0);
    minishell(&core);
    return core.exit;
}