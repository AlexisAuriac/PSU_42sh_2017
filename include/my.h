/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** Contains the prototypes of all the functions exposed by libmy.a.
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <stdbool.h>

#define ALLOW "abcdefghijklmnopqrstuvwxyz"
#define ALUP "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUM "0123456789"
#define ALPHA_NUM ALLOW ALUP NUM "_"

#define READ_SIZE 5

#ifndef __GNUC__
#	define __attribute__(__VA_ARG__)
#endif

//files
__attribute__((warn_unused_result))
char *get_next_line(int fd);

//alloc
__attribute__((nonnull))
void my_free_array(void **arr);

//my_str -> infos
__attribute__((nonnull (2), warn_unused_result))
bool in_str(char const c, char const *str);
__attribute__((nonnull, warn_unused_result))
bool my_str_is(const char *str, const char *allowed);
__attribute__((nonnull, warn_unused_result))
bool my_str_is_signednum(char *str);

//my_str -> word array
__attribute__((nonnull, warn_unused_result))
char **my_str_split(const char *str, const char *seps);
__attribute__((nonnull, warn_unused_result))
int my_strlen_tab(void * const *arr);
__attribute__((nonnull, warn_unused_result))
char *my_str_join(char **arr, const char *joint);

//my_str -> write
char *my_append(char *str, char const *cat);

#endif
