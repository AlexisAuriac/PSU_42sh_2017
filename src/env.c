/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the environnement.
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "shell.h"

static char **env_cpy(char **cpy, char **envp)
{
	for (int i = 0 ; envp[i] ; ++i) {
		cpy[i] = strdup(envp[i]);
		if (cpy[i] == NULL) {
			perror("malloc");
			while (i--)
				free(cpy[i]);
			free(cpy);
			return (NULL);
		}
	}
	return (cpy);
}

char **env_dup(char **envp)
{
	int nb_vars = 0;
	char **cpy = NULL;

	nb_vars = my_strlen_tab((void **) envp);
	cpy = malloc(sizeof(char *) * (nb_vars + 1));
	if (cpy == NULL) {
		perror("malloc");
		return (NULL);
	}
	cpy[nb_vars] = NULL;
	cpy = env_cpy(cpy, envp);
	return (cpy);
}

int get_pos_env(char **env, char *name)
{
	int len = strlen(name);

	for (int i = 0 ; env[i] ; ++i) {
		if (strncmp(env[i], name, len) == 0 && env[i][len] == '=')
			return (i);
	}
	return (-1);
}