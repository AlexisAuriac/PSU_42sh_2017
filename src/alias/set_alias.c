/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Sets an alias.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "shell.h"

alias_t *create_alias(const char *name, const char *value)
{
	alias_t *alias = calloc(1, sizeof(node_t));

	if (alias == NULL) {
		perror("malloc");
		return (NULL);
	}
	alias->name = strdup(name);
	if (alias->name == NULL) {
		perror("malloc in strdup");
		free(alias);
		return (NULL);
	}
	alias->value = strdup(value);
	if (alias->value == NULL) {
		perror("malloc in strdup");
		free(alias->name);
		free(alias);
		return (NULL);
	}
	return (alias);
}

static void replace_alias(alias_t *alias, const char *value)
{
	char *new_value = strdup(value);

	if (new_value == NULL) {
		perror("malloc");
		return;
	}
	free(alias->value);
	alias->value = new_value;
}

static void add_alias(alias_t *alias, const char *name, const char *value)
{
	int diff = strcmp(alias->name, name);

	if (diff > 0) {
		if (alias->lower != NULL)
			add_alias(alias->lower, name, value);
		else
			alias->lower = create_alias(name, value);
	} else if (diff < 0) {
		if (alias->higher != NULL)
			add_alias(alias->higher, name, value);
		else
			alias->higher = create_alias(name, value);
	} else
		replace_alias(alias, value);
}

void set_alias(shell_t *mysh, const char *name, const char *value)
{
	if (mysh->alias == NULL)
		mysh->alias = create_alias(name, value);
	else
		add_alias(mysh->alias, name, value);
}