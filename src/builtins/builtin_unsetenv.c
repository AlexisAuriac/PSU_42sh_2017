/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Unsets an environnement variable.
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "shell.h"

static bool error_unsetenv(char **command)
{
	if (my_strlen_tab((void **) command) < 2) {
		ERROR_UNSETENV_TOO_FEW_ARG;
		return (true);
	}
	return (false);
}

static int del_env_var(char **env, char *name, int nb_vars)
{
	int len = strlen(name);

	for (int i = 0 ; i < nb_vars ; ++i) {
		if (env[i] == NULL)
			continue;
		if (strncmp(env[i], name, len) == 0 && env[i][len] == '=') {
			free(env[i]);
			env[i] = NULL;
			return (1);
		}
	}
	return (0);
}

static char **copy_incomplete_env(char **env, int nb_vars, int unset_vars)
{
	char **copy = malloc(sizeof(char *) * (nb_vars - unset_vars + 1));

	if (copy == NULL) {
		perror("malloc");
		return (NULL);
	}
	for (int i = 0, j = 0 ; j < nb_vars ; ++i, ++j) {
		while (env[j] == NULL && j < nb_vars)
			++j;
		copy[i] = env[j];
	}
	copy[nb_vars - unset_vars] = NULL;
	return (copy);
}

void builtin_unsetenv(shell_t *mysh, char **command)
{
	char **copy = NULL;
	int nb_vars = 0;
	int unset_vars = 0;

	if (error_unsetenv(command)) {
		mysh->exit_status = 1;
		return;
	}
	nb_vars = my_strlen_tab((void **) mysh->env);
	for (int i = 1 ; command[i] ; ++i)
		unset_vars += del_env_var(mysh->env, command[i], nb_vars);
	copy = copy_incomplete_env(mysh->env, nb_vars, unset_vars);
	if (copy == NULL) {
		mysh->exit_status = 1;
		return;
	}
	free(mysh->env);
	mysh->env = copy;
	mysh->exit_status = 0;
}