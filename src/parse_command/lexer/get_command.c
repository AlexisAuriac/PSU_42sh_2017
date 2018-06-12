/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Recuperates the command from the users' input.
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "shell.h"

static void cut_comment(char *str)
{
	char *com = index(str, '#');

	if (com != NULL)
		*com = '\0';
}

node_t *parse_line(char *line, shell_t *mysh)
{
	node_t *tree = NULL;

	cut_comment(line);
	if (!check_quotes(line))
		return (NULL);
	tree = ll_lexer(line, mysh);
	return (tree);
}

node_t *get_command(shell_t *mysh)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t byte_read = getline(&line, &n, stdin);
	node_t *tree = NULL;

	if (byte_read == -1) {
		mysh->stop = true;
		free(line);
		if (mysh->tty)
			puts("exit");
		return (NULL);
	}
	line[byte_read - 1] = '\0';
	tree = parse_line(line, mysh);
	free(line);
	if (tree == NULL) {
		mysh->exit_status = 1;
		return (NULL);
	}
	return (tree);
}
