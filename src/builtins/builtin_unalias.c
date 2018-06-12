/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Unsets an alias.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "shell.h"

static void relocate_alias(alias_t *orphan, alias_t *parent)
{
	int diff = strcmp(parent->name, orphan->name);

	if (diff > 0) {
		if (parent->lower == NULL)
			parent->lower = orphan;
		else
			relocate_alias(orphan, parent->lower);
	} else if (diff < 0) {
		if (parent->higher == NULL)
			parent->higher = orphan;
		else
			relocate_alias(orphan, parent->lower);
	}
}

static void how_to_unalias(alias_t *tree, alias_t **link_prev)
{
	if (tree->lower == NULL && tree->higher == NULL)
		*link_prev = NULL;
	else if (tree->lower != NULL && tree->higher != NULL) {
		*link_prev = tree->lower;
		relocate_alias(tree->higher, tree->lower);
	} else
		*link_prev = (tree->lower) ? tree->lower : tree->higher;
}

static bool unalias(alias_t *tree, alias_t **link_prev, char *to_unalias)
{
	int diff = strcmp(tree->name, to_unalias);

	if (diff > 0) {
		if (tree->lower == NULL)
			return (false);
		return (unalias(tree->lower, &tree->lower, to_unalias));
	} else if (diff < 0) {
		if (tree->higher == NULL)
			return (false);
		return (unalias(tree->higher, &tree->higher, to_unalias));
	} else {
		how_to_unalias(tree, link_prev);
		del_alias(tree);
		return (true);
	}
}

void builtin_unalias(shell_t *mysh, char **command)
{
	int invalid = 0;

	if (command[1] == NULL) {
		ERROR_UNALIAS_TOO_FEW_ARG;
		mysh->exit_status = 1;
		return;
	} else if (strcmp(command[1], "-a") == 0) {
		del_alias(mysh->alias);
		mysh->alias = NULL;
		mysh->exit_status = 0;
	} else {
		for (int i = 1 ; command[i] ; ++i) {
			if (!unalias(mysh->alias, &mysh->alias, command[i]))
				++invalid;
		}
		if (!invalid)
			mysh->exit_status = 0;
		else
			mysh->exit_status = 1;
	}
}