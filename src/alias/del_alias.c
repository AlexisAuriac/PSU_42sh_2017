/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Deletes all aliases.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "shell.h"

void del_alias(alias_t *alias)
{
	free(alias->name);
	free(alias->value);
	free(alias);
}

void del_alias_tree(alias_t *alias)
{
	if (alias->higher != NULL)
		del_alias_tree(alias->higher);
	if (alias->lower != NULL)
		del_alias_tree(alias->lower);
	del_alias(alias);
}