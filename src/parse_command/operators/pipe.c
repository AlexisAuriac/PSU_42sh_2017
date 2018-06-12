/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the pipe '|' operator.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

static _Noreturn void redir_output(shell_t *mysh, node_t *left, int *pipefd)
{
	int save_stdout = dup(STDOUT_FILENO);

	if (save_stdout == -1) {
		perror("dup");
		exit(1);
	}
	if (close(pipefd[0]) == -1)
		perror("close");
	if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
		perror("dup2");
		exit(1);
	}
	exec_tree(mysh, left);
	if (dup2(save_stdout, STDOUT_FILENO) == -1)
		perror("dup2");
	exit(mysh->exit_status);
}

static bool use_redirected_output(shell_t *mysh, node_t *right, int *pipefd)
{
	int save_stdin = dup(STDIN_FILENO);

	if (close(pipefd[1]) == -1)
		perror("close");
	if (dup2(pipefd[0], STDIN_FILENO) == -1) {
		perror("dup2");
		mysh->exit_status = 1;
		return (false);
	}
	exec_tree(mysh, right);
	if (dup2(save_stdin, STDIN_FILENO) == -1) {
		perror("dup2");
		return (false);
	}
	return (true);
}

bool exec_pipe(shell_t *mysh, node_t *left, node_t *right)
{
	int pipefd[2];
	pid_t child_process;

	if (pipe(pipefd) == -1) {
		perror("pipe");
		return (false);
	}
	child_process = fork();
	if (child_process == -1) {
		perror("fork");
		return (false);
	} else if (child_process == 0)
		redir_output(mysh, left, pipefd);
	return (use_redirected_output(mysh , right, pipefd));
}