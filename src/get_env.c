/*
** EPITECH PROJECT, 2020
** minishell1_v2
** File description:
** get_env
*/

#include "my.h"

static void store_path(core_t *core, char *buffer)
{
    node_t *nav = core->paths;
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        exit(strerr("MALLOC FAILED\n"));
    node->data = buffer;
    node->next = NULL;
    if (core->paths == NULL) {
        core->paths = node;
        return;
    }
    while (nav->next != NULL)
        nav = nav->next;
    nav->next = node;
}

void get_paths(char *path, size_t i, core_t *core)
{
    char *buffer = NULL;

    if (path[i] == '\n' || path[i] == '\0')
        return;
    if (path[i] == ':' && path[i + 1] != '\0')
        i++;
    for (; path[i] && path[i] != ':' && path[i] != '\n'; i++)
        buffer = update_str(buffer, path[i]);
    store_path(core, buffer);
    get_paths(path, i, core);
}

static char *get_usr(char *usr)
{
    int j = 0;
    char *res = malloc(sizeof(char) * (str_len(usr)));

    for (int i = 9; usr[i] ; i++, j++)
        res[j] = usr[i];
    res[j] = '\0';
    return (res);
}

void get_env(core_t *core)
{
    for (size_t i = 0; core->env[i]; i++) {
        if (str_in_str(core->env[i], "USERNAME=") == true)
            core->user = get_usr(core->env[i]);
        if (core->env[i][0] == 'P' && core->env[i][1] == 'A' && core->env[i][2]\
        == 'T' && core->env[i][3] == 'H' && core->env[i][4] == '=')
            get_paths(core->env[i], 5, core);
    }
}