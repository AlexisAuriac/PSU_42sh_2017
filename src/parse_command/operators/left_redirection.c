/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the left redirection '<' operator.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

static bool setup_left_redir(int *save_stdin, int *in, const char *filename)
{
	*save_stdin = dup(STDIN_FILENO);
	if (*save_stdin == -1) {
		perror("dup");
		return (false);
	}
	*in = open(filename, O_RDONLY);
	if (*in == -1) {
		perror("open");
		return (false);
	}
	if (dup2(*in, STDIN_FILENO) == -1) {
		perror("dup2");
		if (close(*in) == -1)
			perror("close");
		return (false);
	}
	return (true);
}

bool exec_l_redir(shell_t *mysh, node_t *left, node_t *right)
{
	int save_stdin;
	int in;

	if (!setup_left_redir(&save_stdin, &in, right->expr[0]))
		return (false);
	exec_tree(mysh, left);
	if (dup2(save_stdin, STDIN_FILENO) == -1)
		perror("dup2");
	if (close(in) == -1)
		perror("close");
	return (true);
}