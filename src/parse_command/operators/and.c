/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the and '&&' operator.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "shell.h"

bool exec_and(shell_t *mysh, node_t *left, node_t *right)
{
	if (exec_tree(mysh, left))
		exec_tree(mysh, right);
	return (true);
}