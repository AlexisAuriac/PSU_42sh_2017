/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the right error double redirection '2>>' operator.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

static bool setup_right_err_dbl_redir(int *save_stderr,
	int *err, const char *filename)
{
	*save_stderr = dup(STDERR_FILENO);
	if (*save_stderr == -1) {
		perror("dup");
		return (false);
	}
	*err = open(filename, O_WRONLY | O_CREAT | O_APPEND, REG_RIGHTS);
	if (*err == -1) {
		perror("open");
		return (false);
	}
	if (dup2(*err, STDERR_FILENO) == -1) {
		perror("dup2");
		if (close(*err) == -1)
			perror("close");
		return (false);
	}
	return (true);
}

bool exec_r_err_dbl_redir(shell_t *mysh, node_t *left, node_t *right)
{
	int save_stderr;
	int err;

	if (!setup_right_err_dbl_redir(&save_stderr, &err, right->expr[0]))
		return (false);
	exec_tree(mysh, left);
	if (dup2(save_stderr, STDERR_FILENO) == -1)
		perror("dup2");
	if (close(err) == -1)
		perror("close");
	return (true);
}