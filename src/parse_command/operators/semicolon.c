/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the semicolon ';' operator.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "shell.h"

bool exec_semicolon(shell_t *mysh, node_t *left, node_t *right)
{
	exec_tree(mysh, left);
	exec_tree(mysh, right);
	return (true);
}