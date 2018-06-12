/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Initialization header.
*/

#ifndef INIT_H
#define INIT_H

/* PROTOTYPES */
//init.c
bool interpret_file(shell_t *mysh, const char *file);
void init_shell(shell_t *mysh, char **av, char **env);

//parse_arg.c
bool parse_arg(shell_t *mysh, char **av);

/* CONSTANT */
static const char CONF_FILE[] = ".42shrc";

/* MACRO */
#define DEFAULT_PATH		\
((char *[]) {"setenv", "PATH", "/bin:/usr/bin:/usr/local/bin/usr/sbin", NULL})

#endif