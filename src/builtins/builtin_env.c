/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Displays the env.
*/

#include "my.h"
#include "shell.h"

void builtin_env(shell_t *mysh, UNUSED char **command)
{
	for (int i = 0 ; mysh->env[i] ; ++i)
		puts(mysh->env[i]);
	mysh->exit_status = 0;
}