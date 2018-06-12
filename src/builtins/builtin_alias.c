/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Alias management.
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "shell.h"

static void show_alias(alias_t *alias, const char *name)
{
	char *value;

	if (alias == NULL)
		return;
	value = find_alias(alias, name);
	if (value != NULL)
		puts(value);
}

void builtin_alias(shell_t *mysh, char **command)
{
	if (command[1] == NULL) {
		if (mysh->alias)
			show_alias_tree(mysh->alias);
	} else if (command[2] == NULL)
		show_alias(mysh->alias, command[1]);
	else
		set_alias(mysh, command[1], command[2]);
	mysh->exit_status = 0;
}