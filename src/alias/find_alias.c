/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Finds an alias in the alias tree.
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "shell.h"

char *find_alias(alias_t *tree, const char *name)
{
	int diff = strcmp(tree->name, name);

	if (diff > 0) {
		if (tree->lower == NULL)
			return (NULL);
		return (find_alias(tree->lower, name));
	} else if (diff < 0) {
		if (tree->higher == NULL)
			return (NULL);
		return (find_alias(tree->higher, name));
	} else
		return (tree->value);
}