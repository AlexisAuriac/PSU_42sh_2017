/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Header file for builtins.
*/

#ifndef BUILTINS_H
#define BUILTINS_H

/* TYPEDEF */
typedef struct builtin {
	const char *name;
	void (*ptr)(shell_t *mysh, char **command);
} builtin_t;


/* FUNCTIONS */
//builtin_exit.c
void builtin_exit(shell_t *mysh, char **command);

//builtin_env.c
void builtin_env(shell_t *mysh, char **command);

//builtin_setenv.c
void builtin_setenv(shell_t *mysh, char **command);

//builtin_unsetenv.c
void builtin_unsetenv(shell_t *mysh, char **command);

//builtin_cd.c
void builtin_cd(shell_t *mysh, char **command);

//builtin_pwd.c
void builtin_pwd(shell_t *mysh, char **command);

//builtin_echo.c
void builtin_echo(shell_t *mysh, char **command);
char *rewrite_arg(char *arg, int *opt_l);

//builtin_jobs.c
void builtin_jobs(shell_t *mysh, char **command);

//builtin_fg.c
void builtin_fg(shell_t *mysh, char **command);

//builtin_alias.c
void builtin_alias(shell_t *mysh, char **command);

//builtin_unalias.c
void builtin_unalias(shell_t *mysh, char **command);

//builtin_true.c
void builtin_true(shell_t *mysh, char **command);

//builtin_false.c
void builtin_false(shell_t *mysh, char **command);

//builtins_help.c
void builtin_help(shell_t *mysh, char **command);

//builtin_repeat.c
void builtin_repeat(shell_t *mysh, char **command);

//builtin_builtin.c
void builtin_builtin(shell_t *mysh, char **command);

/* CONSTANTS */
static const builtin_t BUILTINS[] = {
	{"exit", builtin_exit},
	{"env", builtin_env},
	{"setenv", builtin_setenv},
	{"unsetenv", builtin_unsetenv},
	{"cd", builtin_cd},
	{"pwd", builtin_pwd},
	{"echo", builtin_echo},
	{"help", builtin_help},
	{"jobs", builtin_jobs},
	{"fg", builtin_fg},
	{"alias", builtin_alias},
	{"unalias", builtin_unalias},
	{"true", builtin_true},
	{"false", builtin_false},
	{"repeat", builtin_repeat},
	{"builtin", builtin_builtin}
};

static const int NB_BUILTINS = 16;

static const char ECHO_SEQS[] = "abefnrtv\\";
static const char ECHO_SEQS_SWITCH[] =
{'\a', '\b', '\e', '\f', '\n', '\r', '\t', '\v', '\\'};


/* ERRORS */
//exit
#define ERROR_EXIT_EXPRESSION		\
puts("exit: Expression Syntax.")

//setenv
#define ERROR_SETENV_TOO_MANY_ARG		\
puts("setenv: Too many arguments.")
#define ERROR_SETENV_FIRST_CHAR		\
puts("setenv: Variable name must begin with a letter.")
#define ERROR_SETENV_ALPHA_NUM		\
puts("setenv: Variable name must contain alphanumeric characters.")

//unsetenv
#define ERROR_UNSETENV_TOO_FEW_ARG		\
puts("unsetenv: Too few arguments.")

//cd
#define ERROR_CD_HOME		\
puts("cd: Can't change to home directory.")
#define ERROR_CD_TOO_MUCH_ARG		\
puts("cd: Too many arguments.")
#define ERROR_CD_NOT_DIR(name)		\
printf("%s: Not a directory.\n", name)

//pwd
#define ERROR_PWD_TOO_MANY_ARG		\
puts("pwd: too many arguments")
#define ERROR_PWD_BAD_OPTION(opt)		\
printf("pwd: bad option: %s\n", opt)

//jobs
#define ERROR_JOBS_TOO_MANY_ARG		\
puts("jobs: Too many arguments.")
#define ERROR_JOBS_USAGE		\
puts("Usage: jobs [ -l ].")

//fg
#define ERROR_FG_NO_JOBS		\
puts("fg: no current job")
#define ERROR_FG_NO_SUCH_JOB(job)		\
printf("fg: %s: no such job\n", job)
#define ERROR_FG_JOB_NOT_FOUND(job)		\
printf("fg: job not found: %s\n", job)

//unalias
#define ERROR_UNALIAS_TOO_FEW_ARG		\
puts("unalias: Too few arguments")

//repeat
#define ERROR_REPEAT_TOO_FEW_ARG		\
puts("repeat: Too few arguments.")
#define ERROR_REPEAT_BAD_NB		\
puts("repeat: Badly formed number.")

//builtin
#define ERROR_BUILTIN_NOT_BUILTIN(name)		\
printf("42sh: builtin: %s: not a shell builtin\n", name);

#endif
