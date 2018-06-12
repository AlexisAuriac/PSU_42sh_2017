/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Displays its arguments.
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "shell.h"

static void my_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

static char echo_char(const char *str, int pos)
{
	char *seq;

	if (str[pos] == '\\') {
		seq = index(ECHO_SEQS, str[pos + 1]);
		if (seq != NULL) {
			my_putchar(ECHO_SEQS_SWITCH[seq - ECHO_SEQS]);
			return (*seq);
		} else if (str[pos + 1] == 'c')
			return ('c');
	} else
		my_putchar(str[pos]);
	return ('\0');
}

void builtin_echo(shell_t *mysh, char **command)
{
	char seq;

	mysh->exit_status = 0;
	for (int i = 1 ; command[i] ; ++i) {
		for (int j = 0 ; command[i][j] ; ++j) {
			seq = echo_char(command[i], j);
			if (seq == 'c')
				return;
			else if (seq)
				++j;
		}
		if (command[i + 1] != NULL)
			my_putchar(' ');
	}
	my_putchar('\n');
}