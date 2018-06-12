/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Repeat a command a certain number of times.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

void builtin_repeat(shell_t *mysh, char **command)
{
	if (command[1] == NULL || command[2] == NULL) {
		ERROR_REPEAT_TOO_FEW_ARG;
		mysh->exit_status = 1;
		return;
	} else if (!my_str_is_signednum(command[1])) {
		ERROR_REPEAT_BAD_NB;
		mysh->exit_status = 1;
		return;
	}
	for (int i = 0 ; i < atoi(command[1]) ; ++i)
		exec_command(mysh, command + 2);
}
