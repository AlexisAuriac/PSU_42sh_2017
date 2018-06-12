/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the or '||' operator.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "shell.h"

bool exec_or(shell_t *mysh, node_t *left, node_t *right)
{
	if (left->expr[0] == NULL || !exec_tree(mysh, left))
		exec_tree(mysh, right);
	return (true);
}