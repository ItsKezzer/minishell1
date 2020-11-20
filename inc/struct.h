/*
** EPITECH PROJECT, 2020
** minishell2_test
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct core
{
    char *home;
    char *user;
    char **env;
    int exit;
    char *pipe_res;
    node_t *paths;
}core_t;

#endif