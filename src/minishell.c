/*
** EPITECH PROJECT, 2020
** minishell_v3
** File description:
** minishell.c
*/

#include "my.h"

static void prompt(core_t *core)
{
    print_str("\e[4m");
    if (!core->user)
        print_str("guest");
    else
        print_str(core->user);
    print_str("\e[0m\e[1m:~");
    print_str(getcwd(NULL, 0));
    print_str("\e[0m>");
}

static char *get_cmd(void)
{
    char *buffer = NULL;
    size_t readsize = 0;
    ssize_t rd = getline(&buffer, &readsize, stdin);

    if (rd <= 0)
        return NULL;
    buffer = clean_str(buffer);
    return buffer;
}

void minishell(core_t *core)
{
    char *in = NULL;

    get_env(core);
    if (core->paths == NULL)
        no_env(core);
    while (1) {
        prompt(core);
        in = get_cmd();
        if (my_exit(core, in) == true)
            return;
        execute(core, in);
        free(in);
        free(core->pipe_res);
        in = NULL;
        core->pipe_res = NULL;
    }
}