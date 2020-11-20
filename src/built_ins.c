/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** built_ins.c
*/

#include "my.h"

static void my_setenv(core_t *core, char **cmd)
{
    size_t i = 0;
    char **new_env = NULL;

    if (alphanum_check(cmd) == false)
        return;
    for (; core->env[i]; i++);
    new_env = malloc(sizeof(char *) * (i + 2));
    if (!new_env)
        exit(strerr("MALLOC FAILED\n"));
    for (i = 0; core->env[i]; i++) {
        new_env[i] = NULL;
        for (size_t j = 0; core->env[i][j] && core->env[i][j] != '\n'; j++)
            new_env[i] = update_str(new_env[i], core->env[i][j]);
    }
    if (!cmd[2])
        new_env[i] = link_strs(cmd[1], "=\n");
    else
        new_env[i] = link_strs(cmd[1], link_strs("=", link_strs(cmd[2], "\n")));
    new_env[i + 1] = NULL;
    core->env = new_env;
}

static void my_unsetenv(core_t *core, char *cmd)
{
    size_t i = 0;
    size_t j = 0;
    char **new_env = NULL;

    for (; core->env[i]; i++);
    new_env = malloc(sizeof(char *) * i);
    if (!new_env)
        exit(strerr("MALLOC FAILED\n"));
    for (i = 0; core->env[i]; i++) {
        if (str_in_str(core->env[i], cmd) == true)
            continue;
        new_env[j] = NULL;
        for (size_t k = 0; core->env[i][k] && core->env[i][k] != '\n'; k++)
            new_env[j] = update_str(new_env[j], core->env[i][k]);
        j++;
    }
    new_env[j] = NULL;
    core->env = new_env;
}

static void my_cd(core_t *core, char **cmd)
{
    char *buffer = getcwd(NULL, 0);

    if (cmd[1] != NULL && chdir(cmd[1]) == 0)
        return;
    if (cmd[1] != NULL && chdir(link_strs(buffer, cmd[1])) == 0) {
        free(buffer);
        return;
    } else if (cmd[1] == NULL && chdir(core->home) == 0)
        return;
    print_str(cmd[1]);
    print_str(": Not a directory.\n");
}

bool built_ins(core_t *core, char **cmd)
{
    if (str_in_str(cmd[0], "unsetenv") == true) {
        for (size_t i = 1; cmd[i]; i++)
            my_unsetenv(core, cmd[i]);
        return true;
    }
    if (str_in_str(cmd[0], "setenv") == true) {
        if (cmd[1] == NULL) {
            cmd[0] = "env\0";
            return false;
        }
        my_setenv(core, cmd);
        return true;
    }
    if (str_in_str(cmd[0], "cd") == true) {
        my_cd(core, cmd);
        return true;
    }
    return false;
}
