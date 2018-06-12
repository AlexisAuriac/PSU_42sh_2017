/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Headers for job control.
*/

#ifndef JOB_H
#define JOB_H

/* TYPEDEF */
typedef struct job {
	int pid;
	char *command;
	struct job *prev;
	struct job *next;
} job_t;

typedef struct job_list {
	job_t *first;
	job_t *last;
	int count;
} job_list_t;

/* FUNCTIONS */
//job_add.c
job_t *job_add(job_list_t *jobs, pid_t pid, node_t *tree);

//job_pop.c
pid_t job_pop(job_list_t *jobs, job_t *job);
pid_t job_pop_pos(job_list_t *jobs, int pos);
pid_t job_pop_name(job_list_t *jobs, char *name);

//job_del.c
void job_free(job_t *proc);
void job_del_all(job_t *list);
void job_cleanup(job_list_t *jobs);

//job_list.c
job_list_t *job_list_init(void);
void job_list_del(job_list_t *jobs);

#endif