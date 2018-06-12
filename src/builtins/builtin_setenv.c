/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Changes the value or creates an environnement variable.
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "shell.h"

static bool error_setenv(char **command, int nb_arg)
{
	if (nb_arg > 3) {
		ERROR_SETENV_TOO_MANY_ARG;
		return (true);
	}
	if (!in_str(command[1][0], ALLOW ALUP)) {
		ERROR_SETENV_FIRST_CHAR;
		return (true);
	} else if (!my_str_is(command[1], ALPHA_NUM)) {
		ERROR_SETENV_ALPHA_NUM;
		return (true);
	}
	return (false);
}

static char *create_env_var(char *name, char *value)
{
	char *var = NULL;
	int size = strlen(name) + 2;

	if (value != NULL)
		size += strlen(value);
	var = malloc(sizeof(char) * size);
	if (var == NULL) {
		perror("malloc");
		return (NULL);
	}
	if (value != NULL)
		sprintf(var, "%s=%s", name, value);
	else
		sprintf(var, "%s=", name);
	return (var);
}

static bool overwrite_env_var(char **env, char *name, char *value, int pos)
{
	char *new_value = create_env_var(name, value);

	if (new_value == NULL)
		return (false);
	free(env[pos]);
	env[pos] = new_value;
	return (true);
}

static bool add_env_var(shell_t *mysh, char *name, char *value)
{
	char **copy = NULL;
	int nb_vars = my_strlen_tab((void **) mysh->env);

	copy = malloc(sizeof(char *) * (nb_vars + 2));
	if (copy == NULL) {
		perror("malloc");
		return (false);
	}
	for (int i = 0 ; mysh->env[i] ; ++i)
		copy[i] = mysh->env[i];
	copy[nb_vars] = create_env_var(name, value);
	if (copy[nb_vars] == NULL) {
		free(copy);
		return (false);
	}
	copy[nb_vars + 1] = NULL;
	free(mysh->env);
	mysh->env = copy;
	return (true);
}

void builtin_setenv(shell_t *mysh, char **command)
{
	int nb_arg = my_strlen_tab((void **) command);
	int pos_var = 0;

	if (nb_arg == 1) {
		builtin_env(mysh, command);
		return;
	} else if (error_setenv(command, nb_arg)) {
		mysh->exit_status = 1;
		return;
	}
	pos_var = get_pos_env(mysh->env, command[1]);
	if (pos_var != -1)
		overwrite_env_var(mysh->env, command[1], command[2], pos_var);
	else
		add_env_var(mysh, command[1], command[2]);
	mysh->exit_status = 0;
}