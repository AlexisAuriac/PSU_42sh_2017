/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Initializes the program.
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include "my.h"
#include "shell.h"

void sigint_hdl(UNUSED int signum)
{
	int status = 0;

	putchar('\n');
	if (waitpid(-1, &status, WNOHANG) == -1)
		display_prompt(1);
}

static void init_signal(void)
{
	struct sigaction sigint = {0};

	sigint.sa_handler = sigint_hdl;
	sigint.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sigint, NULL);
}

static node_t *get_config_command(shell_t *mysh, FILE *conf)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t byte_read = getline(&line, &n, conf);
	node_t *tree = NULL;

	if (byte_read == -1) {
		mysh->stop = true;
		free(line);
		return (NULL);
	}
	if (line[byte_read - 1] == '\n')
		line[byte_read - 1] = '\0';
	tree = parse_line(line, mysh);
	free(line);
	if (tree == NULL) {
		mysh->exit_status = 1;
		return (NULL);
	}
	return (tree);
}

bool interpret_file(shell_t *mysh, const char *file)
{
	FILE *conf = fopen(file, "r");
	node_t *tree = NULL;

	if (conf == NULL)
		return (false);
	while (!mysh->stop) {
		tree = get_config_command(mysh, conf);
		if (tree != NULL) {
			exec_tree(mysh, tree);
			del_tree(tree);
		}
	}
	mysh->stop = false;
	if (fclose(conf) == EOF)
		perror("fclose");
	return (true);
}

void init_shell(shell_t *mysh, char **av, char **env)
{
	mysh->env = env_dup(env);
	if (mysh->env && get_pos_env(mysh->env, "PATH") == -1)
		builtin_setenv(mysh, DEFAULT_PATH);
	mysh->tty = isatty(STDIN_FILENO);
	mysh->jobs = job_list_init();
	for (int i = 0 ; DEF_ALIASES_NAMES[i] ; ++i)
		set_alias(mysh, DEF_ALIASES_NAMES[i], DEF_ALIASES_VAL[i]);
	if (parse_arg(mysh, av))
		mysh->stop = true;
	else
		interpret_file(mysh, CONF_FILE);
	init_signal();
}