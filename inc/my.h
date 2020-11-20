/*
** EPITECH PROJECT, 2020
** minishell1_v2
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include "libs.h"
#include "lib.h"
#include "struct.h"

void execute(core_t *, char *); // Executes the input
void get_env(core_t *); // Get info from the env
void minishell(core_t *); // Minishell engine
void get_paths(char *, size_t, core_t *); // Gets paths from the env
void no_env(core_t *); // Create a basic env if none is found
bool built_ins(core_t *, char **); // execute built ins
char *clean_str(char *); // Cleans string of unnecessary spaces and tabs
bool my_exit(core_t *, char *); // Exits minishell with appropriate value
int *pipe_create(char *, size_t); // Creates a pipe if need be
void piped_res(core_t *, int *); // stores output for next pipe
bool alphanum_check(char **); // Checks if cmd is alphanumeric or not
char **update_cmd(core_t *, char **); // Updates cmd with previous pipe result

#endif
