/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Shows all alias.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "shell.h"

void show_alias_tree(alias_t *tree)
{
	if (tree->lower != NULL)
		show_alias_tree(tree->lower);
	printf("%s\t%s\n", tree->name, tree->value);
	if (tree->higher != NULL)
		show_alias_tree(tree->higher);
}