/*
** EPITECH PROJECT, 2020
** minishell_v3
** File description:
** execute.c
*/

#include "my.h"

static void free_values(char *current, char **cmd)
{
    ssize_t i = 0;

    free(current);
    for (; cmd[i]; i++);
    for (; i > 0; i--)
        free(cmd[i]);
    free(cmd);
}

static char *get_cmdpath(core_t *core, char **cmd)
{
    char *buffer;
    node_t *cpath = core->paths;

    while (cpath != NULL) {
        buffer = link_strs(link_strs(cpath->data, "/"), cmd[0]);
        if (access(buffer, F_OK) == 0) {
            return buffer;
        }
        free(buffer);
        cpath = cpath->next;
    }
    print_str(cmd[0]);
    print_str(": Command not found.\n");
    return NULL;
}

static void run(core_t *core, char **cmd, char *in, size_t i)
{
    int pid;
    int status;
    char *path = get_cmdpath(core, cmd);
    int *fds = pipe_create(in, i);

    if (!path)
        return;
    if ((pid = fork()) == 0) {
        if (fds != NULL) {
            close(fds[0]);
            dup2(fds[1], 1);
            close(fds[1]);
            cmd = update_cmd(core, cmd);
        }
        execve(path, cmd, core->env);
        exit(0);
    }
    waitpid(pid, &status, 0);
    free(path);
    if (fds != NULL)
        piped_res(core, fds);
}

void execute(core_t *core, char *in)
{
    char *current = NULL;
    char **cmd = NULL;

    for (size_t i = 0; in[i] && in[i] != '\n'; i++) {
        for (; in[i] != ';' && in[i] != '|' && in[i] && in[i] != '\n'; i++)
            current = update_str(current, in[i]);
        current = clean_str(current);
        cmd = str_to_word_array(current);
        if (built_ins(core, cmd) != true)
            run(core, cmd, in, i);
        free_values(current, cmd);
        current = NULL;
        cmd = NULL;
    }
}