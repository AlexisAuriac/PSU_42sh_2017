/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Pops elements from the job linked list.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

pid_t job_pop(job_list_t *jobs, job_t *job)
{
	int pid;

	if (job == NULL)
		return (0);
	pid = job->pid;
	if (job->prev == NULL)
		jobs->first = job->next;
	else
		job->prev->next = job->next;
	if (job->next == NULL)
		jobs->last = job->prev;
	else
		job->next->prev = job->prev;
	job_free(job);
	--jobs->count;
	return (pid);
}

pid_t job_pop_pos(job_list_t *jobs, int pos)
{
	job_t *cur = jobs->first;

	if (pos <= 0 || pos > jobs->count)
		return (0);
	for (int i = 1 ; i < pos && cur ; ++i)
		cur = cur->next;
	return (job_pop(jobs, cur));
}

pid_t job_pop_name(job_list_t *jobs, char *name)
{
	job_t *cur = jobs->last;
	int len_name = strlen(name);

	while (cur) {
		if (strncmp(cur->command, name, len_name) == 0)
			break;
		cur = cur->prev;
	}
	return (job_pop(jobs, cur));
}