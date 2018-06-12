/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the right redirection '>' operator.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

static bool setup_right_redir(int *save_stdout, int *out, const char *filename)
{
	*save_stdout = dup(STDOUT_FILENO);
	if (*save_stdout == -1) {
		perror("dup");
		return (false);
	}
	*out = open(filename, O_WRONLY | O_CREAT | O_TRUNC, REG_RIGHTS);
	if (*out == -1) {
		perror("open");
		return (false);
	}
	if (dup2(*out, STDOUT_FILENO) == -1) {
		perror("dup2");
		if (close(*out) == -1)
			perror("close");
		return (false);
	}
	return (true);
}

bool exec_r_redir(shell_t *mysh, node_t *left, node_t *right)
{
	int save_stdout;
	int out;

	if (!setup_right_redir(&save_stdout, &out, right->expr[0]))
		return (false);
	exec_tree(mysh, left);
	if (dup2(save_stdout, STDOUT_FILENO) == -1)
		perror("dup2");
	if (close(out) == -1)
		perror("close");
	return (true);
}