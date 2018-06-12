/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the shell's arguments.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "shell.h"

bool parse_arg(shell_t *mysh, char **av)
{
	node_t *tree;

	if (av[1] == NULL)
		return (false);
	if (strcmp(av[1], "-c") == 0) {
		if (av[2] != NULL) {
			tree = parse_line(av[2], mysh);
			exec_tree(mysh, tree);
			del_tree(tree);
		}
	} else if (!interpret_file(mysh, av[1]))
		ERROR_NO_FILE(av[1]);
	return (true);
}