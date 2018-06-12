/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Return 1.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "shell.h"

void builtin_false(shell_t *mysh, UNUSED char **command)
{
	mysh->exit_status = 1;
}