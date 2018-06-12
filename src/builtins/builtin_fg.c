/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Takes a job and puts it in the foreground.
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <wait.h>
#include <stdbool.h>
#include "shell.h"

static void bring_to_foreground(shell_t *mysh, pid_t pid)
{
	tcsetpgrp(STDIN_FILENO, pid);
	waitpid(pid, &mysh->exit_status, 0);
	mysh->exit_status %= 256;
}

static pid_t fg_by_id(job_list_t *jobs, char *arg)
{
	int pos = atoi(arg + 1);
	pid_t pid = 0;

	if (pos != 0)
		pid = job_pop_pos(jobs, pos);
	if (pid == 0)
		ERROR_FG_NO_SUCH_JOB(arg);
	return (pid);
}

static pid_t fg_by_name(job_list_t *jobs, char *arg)
{
	pid_t pid = job_pop_name(jobs, arg);

	if (pid == 0)
		ERROR_FG_JOB_NOT_FOUND(arg);
	return (pid);
}

static pid_t fg_by_param(job_list_t *jobs, char *arg)
{
	if (arg[0] == '%' && isdigit(arg[1]))
		return (fg_by_id(jobs, arg));
	else
		return (fg_by_name(jobs, arg));
}

void builtin_fg(shell_t *mysh, char **command)
{
	pid_t pid = 0;

	job_cleanup(mysh->jobs);
	if (mysh->jobs->last == NULL) {
		ERROR_FG_NO_JOBS;
		mysh->exit_status = 1;
		return;
	} else if (command[1] == NULL) {
		pid = job_pop(mysh->jobs, mysh->jobs->last);
		bring_to_foreground(mysh, pid);
	}
	for (int i = 1 ; command[i] ; ++i) {
		pid = fg_by_param(mysh->jobs, command[i]);
		if (pid == 0) {
			mysh->exit_status = 1;
			return;
		}
		bring_to_foreground(mysh, pid);
	}
	mysh->exit_status = 0;
}