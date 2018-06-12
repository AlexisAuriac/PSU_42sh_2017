/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Heart of the project.
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <linux/limits.h>
#include "my.h"
#include "shell.h"

void display_prompt(int status)
{
	char path[PATH_MAX + 1] = "";
	char *dir;

	if (getcwd(path, PATH_MAX) == NULL) {
		perror("getcwd");
		return;
	}
	dir = rindex(path, '/');
	if (dir != path)
		++dir;
	dprintf(STDOUT_FILENO, "%d -> (42sh %s)$ ", status, dir);
}

void shell(shell_t *mysh)
{
	node_t *tree = NULL;

	while (!mysh->stop) {
		if (mysh->tty)
			display_prompt(mysh->exit_status);
		tree = get_command(mysh);
		if (tree != NULL) {
			exec_tree(mysh, tree);
			del_tree(tree);
		}
	}
}