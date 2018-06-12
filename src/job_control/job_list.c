/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the job list.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "shell.h"

job_list_t *job_list_init(void)
{
	job_list_t *jobs = malloc(sizeof(job_list_t));

	if (jobs == NULL) {
		perror("malloc");
		return (NULL);
	}
	jobs->first = NULL;
	jobs->last = NULL;
	jobs->count = 0;
	return (jobs);
}

void job_list_del(job_list_t *jobs)
{
	job_del_all(jobs->first);
	free(jobs);
}