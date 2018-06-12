/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Adds a job.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

static void add_expr_job_command(char **command, char **expr)
{
	char *join_expr = my_str_join(expr, " ");

	if (join_expr == NULL)
		return;
	*command = my_append(*command, join_expr);
	free(join_expr);
}

static void add_op_job_command(char **command, const char *token)
{
	int len = strlen(*command);

	*command = realloc(*command, len + 3 + strlen(token));
	if (*command == NULL) {
		perror("realloc");
		return;
	}
	sprintf(*command + len, " %s ", token);
}

static void get_job_command(node_t *tree, char **command)
{
	if (tree->left != NULL)
		get_job_command(tree->left, command);
	if (tree->op == EXPR)
		add_expr_job_command(command, tree->expr);
	else
		add_op_job_command(command, TOKENS[tree->op]);
	if (tree->right != NULL)
		get_job_command(tree->right, command);
}

static job_t *job_create(pid_t pid, node_t *tree)
{
	job_t *job = calloc(1, sizeof(job_t));

	if (job == NULL) {
		perror("malloc");
		return (NULL);
	}
	get_job_command(tree, &job->command);
	if (job->command == NULL) {
		perror("malloc");
		free(job);
		return (NULL);
	}
	job->pid = pid;
	return (job);
}

job_t *job_add(job_list_t *jobs, pid_t pid, node_t *tree)
{
	job_t *new_elem = job_create(pid, tree);

	if (new_elem == NULL)
		return (NULL);
	if (jobs->last == NULL) {
		jobs->first = new_elem;
		jobs->last = new_elem;
	} else {
		jobs->last->next = new_elem;
		new_elem->prev = jobs->last;
		jobs->last = new_elem;
	}
	++jobs->count;
	return (new_elem);
}