/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Quits the shell.
*/

#include <stdlib.h>
#include "my.h"
#include "shell.h"

void builtin_exit(shell_t *mysh, char **command)
{
	int len = my_strlen_tab((void **) command);

	if (len > 2 || (len == 2 && !my_str_is_signednum(command[1]))) {
		ERROR_EXIT_EXPRESSION;
		mysh->exit_status = 1;
		return;
	} else if (len == 2)
		mysh->exit_status = atoi(command[1]) % 256;
	mysh->stop = true;
	puts("exit");
}