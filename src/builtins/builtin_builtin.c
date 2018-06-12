/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Executes a builtin.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "shell.h"

void builtin_builtin(shell_t *mysh, char **command)
{
	if (command[1] == NULL) {
		mysh->exit_status = 0;
		return;
	}
	for (int i = 0 ; i < NB_BUILTINS ; ++i) {
		if (strcmp(command[1], BUILTINS[i].name) == 0) {
			BUILTINS[i].ptr(mysh, command + 1);
			mysh->exit_status = 0;
			return;
		}
	}
	ERROR_BUILTIN_NOT_BUILTIN(command[1]);
	mysh->exit_status = 1;
}
