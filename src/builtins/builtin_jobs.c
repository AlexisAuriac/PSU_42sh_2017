/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Displays the current jobs.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "shell.h"

void show_all_jobs(job_list_t *jobs, bool disp_pid)
{
	job_t *cur;
	int i = 1;

	job_cleanup(jobs);
	cur = jobs->first;
	while (cur) {
		if (disp_pid)
			printf("[%d] %d %s\n", i, cur->pid, cur->command);
		else
			printf("[%d] %s\n", i, cur->command);
		++i;
		cur = cur->next;
	}
}

void builtin_jobs(shell_t *mysh, char **command)
{
	bool disp_pid = false;

	if (command[1] != NULL) {
		if (command[2] != NULL) {
			ERROR_JOBS_TOO_MANY_ARG;
			mysh->exit_status = 1;
			return;
		} else if (strcmp(command[1], "-l")) {
			ERROR_JOBS_USAGE;
			mysh->exit_status = 1;
			return;
		}
		disp_pid = true;
	}
	show_all_jobs(mysh->jobs, disp_pid);
	mysh->exit_status = 0;
}