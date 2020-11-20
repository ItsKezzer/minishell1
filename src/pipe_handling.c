/*
** EPITECH PROJECT, 2020
** minishell_v3
** File description:
** pipe.c
*/

#include "my.h"

int *pipe_create(char *in, size_t i)
{
    int *fds = NULL;

    if (in[i] == '|')
        pipe(fds);
    return fds;
}

void piped_res(core_t *core, int *fds)
{
    char b;

    close(fds[1]);
    if (core->pipe_res) {
        free(core->pipe_res);
        core->pipe_res = NULL;
    }
    while (read(fds[0], &b, 1) > 0)
        core->pipe_res = update_str(core->pipe_res, b);
    close(fds[0]);
}

char **update_cmd(core_t *core, char **cmd)
{
    char **new = NULL;
    ssize_t i = 0;

    for (; cmd[i]; i++);
    new = malloc(sizeof(char *) * (i + 2));
    if (!new)
        return NULL;
    for (i = 0; cmd[i]; i++)
        new[i] = cmd[i];
    new[i] = core->pipe_res;
    new[i + 1] = NULL;
    for (; i > 0; i--)
        free(cmd[i]);
    free(cmd);
    return new;
}