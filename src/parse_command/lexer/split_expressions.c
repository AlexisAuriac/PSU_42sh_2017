/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Splits the strings at the extremities of the tree into arrays of strings.
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

bool split_expressions(node_t *node)
{
	if (node->left != NULL && !split_expressions(node->left))
		return (false);
	if (node->right != NULL && !split_expressions(node->right))
		return (false);
	if (node->op == EXPR) {
		node->expr = rec_split_words(node->str, 0);
		if (node->expr == NULL) {
			perror("malloc");
			return (false);
		}
	}
	return (true);
}