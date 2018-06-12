/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Splits a node if it contains a token.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "shell.h"

bool error_semicolon(UNUSED node_t *left, UNUSED node_t *right)
{
	return (false);
}

bool error_pipe(node_t *left, node_t *right)
{
	if (is_null_command(left) || is_null_command(right)) {
		ERROR_NULL_COMMAND;
		return (true);
	} else if (OP_ERRORS_PATTERNS[right->op] == ERR_PAT_LEFT_REDIR) {
		ERROR_AMBIGUOUS_INPUT;
		return (true);
	}
	return (false);
}

bool error_r_redir(node_t *left, node_t *right)
{
	if (is_null_command(right)) {
		ERROR_MISSING_NAME_REDIR;
		return (true);
	} else if (is_null_command(left)) {
		ERROR_NULL_COMMAND;
		return (true);
	}
	if (OP_ERRORS_PATTERNS[right->op] == ERR_PAT_PIPE ||
		OP_ERRORS_PATTERNS[right->op] == ERR_PAT_RIGHT_REDIR ||
		OP_ERRORS_PATTERNS[right->op] == ERR_PAT_LEFT_REDIR) {
		ERROR_AMBIGUOUS_OUTPUT;
		return (true);
	}
	return (false);
}

bool error_l_redir(node_t *left, node_t *right)
{
	if (is_null_command(right)) {
		ERROR_MISSING_NAME_REDIR;
		return (true);
	} else if (is_null_command(left)) {
		ERROR_NULL_COMMAND;
		return (true);
	}
	if (OP_ERRORS_PATTERNS[right->op] == ERR_PAT_RIGHT_REDIR ||
		OP_ERRORS_PATTERNS[right->op] == ERR_PAT_LEFT_REDIR) {
		ERROR_AMBIGUOUS_INPUT;
		return (true);
	}
	return (false);
}