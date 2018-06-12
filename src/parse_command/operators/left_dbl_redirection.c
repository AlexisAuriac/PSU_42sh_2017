/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the left double redirection '<<' operator.
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

static _Noreturn void get_input_to_redirect(const char *stop, int *fds)
{
	char *line = NULL;

	close(fds[0]);
	do {
		if (line != NULL) {
			dprintf(fds[1], "%s\n", line);
			free(line);
		}
		dprintf(STDOUT_FILENO, "? ");
		line = get_next_line(STDIN_FILENO);
	} while (line != NULL && strcmp(line, stop));
	if (line != NULL)
		free(line);
	exit(0);
}

static bool use_redirected_input(shell_t *mysh,
	node_t *left, int *pipefd, pid_t child_pid)
{
	int save_stdin = dup(STDIN_FILENO);

	if (close(pipefd[1]) == -1)
		perror("close");
	if (save_stdin == -1) {
		perror("dup");
		return (false);
	}
	waitpid(child_pid, &mysh->exit_status, 0);
	if (dup2(pipefd[0], STDIN_FILENO) == -1) {
		perror("dup2");
		return (false);
	}
	exec_tree(mysh, left);
	if (dup2(save_stdin, STDIN_FILENO) == -1)
		perror("dup2");
	return (true);
}

bool exec_l_dbl_redir(shell_t *mysh, node_t *left, node_t *right)
{
	int pipefd[2];
	pid_t child_pid;

	if (pipe(pipefd) == -1) {
		perror("pipe");
		return (false);
	}
	child_pid = fork();
	if (child_pid == -1) {
		perror("fork");
		return (false);
	}
	if (child_pid == -1)
		return (false);
	else if (child_pid == 0)
		get_input_to_redirect(right->expr[0], pipefd);
	return (use_redirected_input(mysh, left, pipefd, child_pid));
}