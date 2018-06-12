/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the right 'and' double redirection '>>&' operator.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

static bool setup_out_redir(int *save_stdout, int fd)
{
	*save_stdout = dup(STDOUT_FILENO);
	if (*save_stdout == -1) {
		perror("dup");
		return (false);
	}
	if (dup2(fd, STDOUT_FILENO) == -1) {
		perror("dup2");
		return (false);
	}
	return (true);
}

static bool setup_err_redir(int *save_stderr, int fd)
{
	*save_stderr = dup(STDERR_FILENO);
	if (*save_stderr == -1) {
		perror("dup");
		return (false);
	}
	if (dup2(fd, STDERR_FILENO) == -1) {
		perror("dup2");
		return (false);
	}
	return (true);
}

static bool setup_right_and_dbl_redir(int *save_stdout,
	int *save_stderr, int *fd, const char *filename)
{
	*fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, REG_RIGHTS);
	if (*fd == -1) {
		perror("open");
		return (false);
	}
	if (!setup_out_redir(save_stdout, *fd)) {
		if (close(*fd) == -1)
			perror("close");
		return (false);
	} else if (!setup_err_redir(save_stderr, *fd)) {
		if (close(*fd) == -1)
			perror("close");
		if (dup2(*save_stdout, STDOUT_FILENO) == -1)
			perror("dup2");
		return (false);
	}
	return (true);
}

bool exec_r_and_dbl_redir(shell_t *mysh, node_t *left, node_t *right)
{
	int save_stdout;
	int save_stderr;
	int fd;

	if (!setup_right_and_dbl_redir
		(&save_stdout, &save_stderr, &fd, right->expr[0]))
		return (false);
	exec_tree(mysh, left);
	if (dup2(save_stdout, STDOUT_FILENO) == -1)
		perror("dup2");
	if (dup2(save_stderr, STDERR_FILENO) == -1)
		perror("dup2");
	if (close(fd) == -1)
		perror("close");
	return (true);
}