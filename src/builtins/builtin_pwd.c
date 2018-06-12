/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Prints the current directory.
*/

#include <unistd.h>
#include <linux/limits.h>
#include "my.h"
#include "shell.h"

void builtin_pwd(shell_t *mysh, UNUSED char **command)
{
	char cwd[PATH_MAX + 1] = "";

	if (my_strlen_tab((void *) command) > 1) {
		ERROR_PWD_TOO_MANY_ARG;
		mysh->exit_status = 1;
		return;
	} else if (getcwd(cwd, PATH_MAX) == NULL) {
		perror("getcwd");
		mysh->exit_status = 1;
		return;
	}
	puts(cwd);
	mysh->exit_status = 0;
}