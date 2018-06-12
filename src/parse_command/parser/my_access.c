/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Verifies that a command exists.
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include "my.h"
#include "shell.h"

static bool error_access(char *name)
{
	struct stat s;

	if (access(name, F_OK)) {
		ERROR_NOT_FOUND(name);
		return (true);
	}
	stat(name, &s);
	if (access(name, X_OK) || S_ISDIR(s.st_mode)) {
		ERROR_PERMISSON(name);
		return (true);
	}
	return (false);
}

static bool access_direct(shell_t *mysh, char *name, char **path)
{
	if (error_access(name)) {
		mysh->exit_status = 1;
		return (false);
	}
	*path = strdup(name);
	if (*path == NULL)
		return (false);
	return (true);
}

static char **get_paths(char **env)
{
	int pos = get_pos_env(env, "PATH");
	char **bin_paths = NULL;

	if (pos == -1)
		return (NULL);
	bin_paths = my_str_split(env[pos] + 5, ":");
	if (bin_paths == NULL)
		perror("malloc");
	return (bin_paths);
}

static bool access_path(char **env, char *name, char **path)
{
	char **bin_paths = get_paths(env);
	int len_name = strlen(name);
	int len = 0;
	bool found = false;

	if (bin_paths == NULL)
		return (false);
	for (int i = 0 ; bin_paths[i] ; ++i) {
		len = strlen(bin_paths[i]) + len_name + 2;
		*path = malloc(sizeof(char) * len);
		sprintf(*path, "%s/%s", bin_paths[i], name);
		if (access(*path, X_OK) == 0) {
			found = true;
			break;
		}
		free(*path);
	}
	my_free_array((void **) bin_paths);
	return (found);
}

bool my_access(shell_t *mysh, char *name, char **path)
{
	if (in_str('/', name))
		return (access_direct(mysh, name, path));
	else if (access_path(mysh->env, name, path))
		return (true);
	else {
		ERROR_NOT_FOUND(name);
		mysh->exit_status = 1;
		return (false);
	}
}