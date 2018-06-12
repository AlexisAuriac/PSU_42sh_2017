/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Header for aliases.
*/

#ifndef ALIAS_H
#define ALIAS_H

/* TYPEDEFS */
typedef struct alias{
	char *name;
	char *value;
	struct alias *lower;
	struct alias *higher;
} alias_t;


/* FUNCTIONS */
//set_alias.c
alias_t *create_alias(const char *name, const char *value);
void set_alias(shell_t *mysh, const char *name, const char *value);

//find_alias.c
char *find_alias(alias_t *tree, const char *name);

//show_alias.c
void show_alias_tree(alias_t *tree);

//del_alias.c
void del_alias(alias_t *alias);
void del_alias_tree(alias_t *alias);


/* CONSTANTS */
static const char * const DEF_ALIASES_NAMES[] =
{
	"-",
	"..",
	"...",
	"....",
	".....",
	"......",
	"ll",
	"l",
	"vi",
	"gaa",
	NULL
};

static const char * const DEF_ALIASES_VAL[] =
{
	"cd -",
	"cd ..",
	"cd ../..",
	"cd ../../..",
	"cd ../../../..",
	"cd ../../../../..",
	"ls -l",
	"ls -lah",
	"vim",
	"git add --all",
	NULL
};


#endif