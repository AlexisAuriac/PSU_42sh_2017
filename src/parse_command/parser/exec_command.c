/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Executes the command given in argument.
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include "my.h"
#include "shell.h"

void exec_command(shell_t *mysh, char **command)
{
	char *path = NULL;

	if (command == NULL || command[0] == NULL)
		return;
	for (int i = 0 ; i < NB_BUILTINS ; ++i) {
		if (strcmp(command[0], BUILTINS[i].name) == 0) {
			BUILTINS[i].ptr(mysh, command);
			return;
		}
	}
	if (my_access(mysh, command[0], &path)) {
		my_exec(mysh, path, command);
		free(path);
	}
}