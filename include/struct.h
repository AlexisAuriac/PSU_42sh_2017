/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Structures header file.
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct job_list job_list_t;
typedef struct alias alias_t;

typedef struct shell {
	char **env;
	job_list_t *jobs;
	alias_t *alias;
	int tty;
	int exit_status;
	bool stop;
} shell_t;

#endif