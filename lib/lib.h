/*
** EPITECH PROJECT, 2020
** lib_c
** File description:
** lib.h
*/

#ifndef LIB_H_
#define LIB_H_

// Libraries
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

// Structures

typedef struct node
{
    char *data;
    struct node *next;
} node_t;

// Functions
int strerr(char *); // Writes a str in error stream and returns 84.
void print_str(char *); // Standard put_str.
size_t str_len(char *); // Returns the lenght of a given str in a size_t type.
char *my_calloc(size_t); // calloc() remake.
char *update_str(char *, char); // Reallocates a str with an extra given char.
int total_words(char const *); // Returns the ammount of words in a str.
int word_size(char const *, int); // Returns the ammount of char(s) in a word.
char **str_to_word_array(char const *); // Returns an array of strs from a str.
bool str_in_str(char *, char *); // Returns true if a str is in another str.
int get_nbr(char const *); // Returns a number from a str into an int format.
void print_nbr(int); // Standard put_nbr.
char *link_strs(char *, char *); // Returns 2 str's fused into one.

#endif