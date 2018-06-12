/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Operators header.
*/

#ifndef OPERATORS_H
#define OPERATORS_H

/* TYPEDEFS */
typedef enum {
	SEMICOLON,
	AND,
	OR,
	JOB_AND,
	PIPE,
	R_1_DBL_REDIR,
	R_2_DBL_REDIR,
	R_AND_DBL_REDIR,
	R_DBL_REDIR,
	R_1_REDIR,
	R_2_REDIR,
	R_AND_REDIR,
	R_REDIR,
	L_DBL_REDIR,
	L_REDIR,
	EXPR=-1
} token_t;

typedef enum {
	ERR_PAT_SEMICOLON,
	ERR_PAT_PIPE,
	ERR_PAT_RIGHT_REDIR,
	ERR_PAT_LEFT_REDIR
} error_pattern_op_t;

typedef struct node node_t;


/* FUNCTIONS */
//semicolon.c
bool exec_semicolon(shell_t *mysh, node_t *left, node_t *right);

//and.c
bool exec_and(shell_t *mysh, node_t *left, node_t *right);

//or.c
bool exec_or(shell_t *mysh, node_t *left, node_t *right);

//pipe.c
bool exec_pipe(shell_t *mysh, node_t *left, node_t *right);

//right_err_dbl_redirection.c
bool exec_r_err_dbl_redir(shell_t *mysh, node_t *left, node_t *right);

//right_and_dbl_redirection.c
bool exec_r_and_dbl_redir(shell_t *mysh, node_t *left, node_t *right);

//right_dbl_redirection.c
bool exec_r_dbl_redir(shell_t *mysh, node_t *left, node_t *right);

//right_err_redirection.c
bool exec_r_err_redir(shell_t *mysh, node_t *left, node_t *right);

//right_and_redirection.c
bool exec_r_and_redir(shell_t *mysh, node_t *left, node_t *right);

//right_redirection.c
bool exec_r_redir(shell_t *mysh, node_t *left, node_t *right);

//left_dbl_redirection.c
bool exec_l_dbl_redir(shell_t *mysh, node_t *left, node_t *right);

//left_redirection.c
bool exec_l_redir(shell_t *mysh, node_t *left, node_t *right);

//job_and.c
bool exec_job_and(shell_t *mysh, node_t *left, node_t *right);


/* CONSTANTS */
static const char * const TK_SEMICOLON[] = {
	";",
	NULL
};

static const char * const TK_AND_OR[] = {
	"&&",
	"||",
	NULL
};

static const char * const TK_UNARY[] = {
	"&",
	NULL
};

static const char * const TK_PIPE_RIGHT_REDIR[] = {
	"|",
	"1>>",
	"2>>",
	">>&",
	">>",
	"1>",
	"2>",
	">&",
	">",
	NULL
};

static const char * const TK_LEFT_REDIR[] = {
	"<<",
	"<",
	NULL
};

static const char * const * const TOKENS_PRIOR[] = {
	TK_SEMICOLON,
	TK_AND_OR,
	TK_UNARY,
	TK_PIPE_RIGHT_REDIR,
	TK_LEFT_REDIR,
	NULL
};

static const char * const TOKENS[] = {
	";",
	"&&",
	"||",
	"&",
	"|",
	"1>>",
	"2>>",
	">>&",
	">>",
	"1>",
	"2>",
	">&",
	">",
	"<<",
	"<",
	NULL
};

static const error_pattern_op_t OP_ERRORS_PATTERNS[] = {
	ERR_PAT_SEMICOLON,
	ERR_PAT_SEMICOLON,
	ERR_PAT_SEMICOLON,
	ERR_PAT_SEMICOLON,
	ERR_PAT_PIPE,
	ERR_PAT_RIGHT_REDIR,
	ERR_PAT_RIGHT_REDIR,
	ERR_PAT_RIGHT_REDIR,
	ERR_PAT_RIGHT_REDIR,
	ERR_PAT_RIGHT_REDIR,
	ERR_PAT_RIGHT_REDIR,
	ERR_PAT_RIGHT_REDIR,
	ERR_PAT_RIGHT_REDIR,
	ERR_PAT_LEFT_REDIR,
	ERR_PAT_LEFT_REDIR,
};

bool error_semicolon(UNUSED node_t *left, UNUSED node_t *right);
bool error_pipe(node_t *left, node_t *right);
bool error_l_redir(node_t *left, node_t *right);
bool error_r_redir(node_t *left, node_t *right);

static bool (*const ERROR_PATTERNS[])
(node_t *left, node_t *right) = {
	error_semicolon,
	error_pipe,
	error_r_redir,
	error_l_redir
};

static const int REG_RIGHTS = S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR | S_IWOTH;

static bool (*const TOKENS_EXEC[])
(shell_t *mysh, node_t *left, node_t *right) = {
	exec_semicolon,
	exec_and,
	exec_or,
	exec_job_and,
	exec_pipe,
	exec_r_dbl_redir,
	exec_r_err_dbl_redir,
	exec_r_and_dbl_redir,
	exec_r_dbl_redir,
	exec_r_redir,
	exec_r_err_redir,
	exec_r_and_redir,
	exec_r_redir,
	exec_l_dbl_redir,
	exec_l_redir,
};


/* ERRORS */
#define ERROR_NULL_COMMAND		\
printf("Invalid null command.\n")
#define ERROR_AMBIGUOUS_OUTPUT		\
printf("Ambiguous output redirect.\n")
#define ERROR_AMBIGUOUS_INPUT		\
printf("Ambiguous input redirect.\n")
#define ERROR_MISSING_NAME_REDIR		\
printf("Missing name for redirect.\n")

#endif
