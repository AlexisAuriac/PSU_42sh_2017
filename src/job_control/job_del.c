/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Deletes elements from the job linked list.
*/

#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

void job_free(job_t *proc)
{
	free(proc->command);
	free(proc);
}

void job_del_all(job_t *list)
{
	job_t *to_del;

	while (list) {
		to_del = list;
		list = list->next;
		job_free(to_del);
	}
}

void job_cleanup(job_list_t *jobs)
{
	job_t *prev;
	job_t *cur = jobs->first;

	while (cur) {
		if (waitpid(cur->pid, NULL, WNOHANG)) {
			if (cur->prev == NULL) {
				job_pop(jobs, cur);
				cur = jobs->first;
			} else {
				prev = cur->prev;
				job_pop(jobs, cur);
				cur = prev->next;
			}
		} else
			cur = cur->next;
	}
	if (jobs->first == NULL)
		jobs->last = NULL;
}