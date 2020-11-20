/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** no_env.c
*/

#include "my.h"

void no_env(core_t *core)
{
    char *username = "guest";

    core->user = NULL;
    for (size_t i = 0; username[i]; i++)
        core->user = update_str(core->user, username[i]);
    get_paths("/home/kezzer/.local/bin:/usr/local/sbin:/usr/local/bin\
    :/usr/sbin:/usr/bin:/sbin:/bin", 0, core);
}