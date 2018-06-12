/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Displays help about builtins.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "shell.h"

void builtin_help(shell_t *mysh, char **command)
{
	if (command[1] == NULL) {
		printf(HELP);
		mysh->exit_status = 0;
		return;
	}
	for (int i = 0 ; i < NB_HELP ; i++) {
		if (strcmp(command[1], TAB_HELP[i]) == 0) {
			printf(TAB_MSG[i]);
			mysh->exit_status = 0;
			return;
		}
	}
	HELP_ERROR(command[1]);
	mysh->exit_status = 1;
}
