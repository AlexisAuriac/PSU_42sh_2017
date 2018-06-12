/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Contains the help messages.
*/

#ifndef HELP_H
#define HELP_H

static const char HELP[] =
"42sh, version 42.42.42(42)-release (x86_64-tek-linux-42sh)\n"
"These shell commands are defined internally.  Type `help' to see this list.\n"
"Type `help name' to find out more about the function `name'.\n"
"Use `man -k' to find out more about commands not in this list. \n\n"
"alias [name [value]]\n"
"builtin [shell-builtin [arg ...]]\n"
"cd [dir]\n"
"echo [arg ...]\n"
"env\n"
"exit [n]\n"
"false\n"
"fg [job_spec ...]\n"
"help [-dms] [pattern ...]\n"
"jobs [-l]\n"
"pwd\n"
"repeat [command [arg ...]]"
"setenv [name [value]]\n"
"true\n"
"unalias [-a] name [name ...]\n"
"unsetenv [arg ...]\n";

static const char HELP_ALIAS[] =
"alias: alias [name [value]]\n"
"\tDefine or display aliases.\n\n"
"\tWithout arguments, `alias' prints the list of aliases in the reusable\n"
"\tform `NAME\tVALUE' on standard output.\n\n"
"\tOtherwise, an alias is defined for the NAME whose VALUE is given.\n\n"
"\tIf VALUE is not specified the value of the NAME given is printed\n"
"\tif it exists.\n\n"
"\tExit Status:\n"
"\talias returns true unless a NAME is supplied for which no alias has been\n"
"\tdefined.\n";

static const char HELP_BUILTIN[] =
"builtin: builtin [shell-builtin [arg ...]]\n"
"\tExecute shell builtins.\n\n"
"\tExecute SHELL-BUILTIN with arguments ARGs without performing command\n"
"\tlookup.  This is useful when you wish to reimplement a shell builtin\n"
"\tas a shell function, "
"but need to execute the builtin within the function.\n\n"
"\tExit Status:\n"
"\tReturns the exit status of SHELL-BUILTIN, or false if SHELL-BUILTIN is\n"
"\tnot a shell builtin..\n";

static const char HELP_CD[] =
"cd: cd [dir]\n"
"\tChange the shell working directory.\n\n"
"\tChange the current directory to DIR.  The default DIR is the value of the\n"
"\tHOME shell variable.\n\n"
"\t`..' is processed by removing the immediately previous pathname component\n"
"\tback to a slash or the beginning of DIR.\n\n"
"\tExit Status:\n"
"\tReturns 0 if the directory is changed, and if $PWD is set successfully.\n"
"\tNon-zero otherwise.\n";

static const char HELP_ECHO[] =
"echo: echo [-neE] [arg ...]\n"
"\tWrite arguments to the standard output.\n"
"\tDisplay the ARGs, separated by a single space character and followed by a\n"
"\tnewline, on the standard output.\n"
"\tOptions:\n"
"\t-n\tdo not append a newline\n"
"\t-e\tenable interpretation of the following backslash escapes\n"
"\t-E\texplicitly suppress interpretation of backslash escapes \n"
"\t'echo' interprets the following backslash-escaped characters:\n"
"\t\\a\talert (bell)\n"
"\t\\b\tbackspace\n"
"\t\\c\tsuppress further output\n"
"\t\\e\tescape character\n"
"\t\\E\tescape character\n"
"\t\\f\tform feed\n"
"\t\\n\tnew line\n"
"\t\\r\tcarriage return\n"
"\t\\t\thorizontal tab\n"
"\t\\v\tvertical tab\n"
"\t\\\\\tbackslash\n"
"\t\\0nnn\tthe character whose ASCII code is NNN (octal).  NNN can be\n"
"\t\t0 to 3 "
"octal digits\n"
"\t\\xHH\tthe eight-bit character whose value is HH (hexadecimal)."
"HH\n"
"\t\tcan be one or two hex digits\n"
"\n"
"\tExit Status:\n"
"\tReturns success unless a write error occurs.\n";

static const char  HELP_ENV[] =
"env: env\n"
"\tDisplays the environnement\n\n"
"\tExit Status:\n"
"\tReturns success\n";

static const char HELP_EXIT[] =
"exit: exit [n]\n"
"\tExit the shell.\n\n"
"\tExits the shell with a status of N. If N is omitted, the exit status\n"
"\tis that of the last command executed.\n";

static const char HELP_FALSE[] =
"false: false\n"
"\tReturn an unsuccessful result.\n\n"
"\tExit Status:\n"
"\tAlways fails.\n";

static const char HELP_FG[] =
"fg: fg [job_spec] \n"
"\tMove job to the foreground.\n\n"
"\tPlace the job identified by JOB_SPEC in the foreground, making it the\n"
"\tcurrent job. If JOB_SPEC is not present, the shell's notion of the\n"
"\tcurrent job is used.\n\n"
"\tExit Status:\n"
"Status of command placed in foreground, or failure if an error occurs.\n";

static const char HELP_HELP[] =
"help: help [-dms] [pattern ...]\n"
"\tDisplay information about builtin commands.\n"
"\tDisplays brief summaries of builtin commands. If PATTERN is \n"
"\tspecified,gives detailed help on all commands matching PATTERN,\n"
"\totherwise the list of help topics is printed.\n"
"\tOptions:\n"
"\t -d\toutput short description for each topic\n"
"\t -m\tdisplay usage in pseudo-manpage format\n"
"\t -s\toutput only a short usage synopsis for each topic matching\n"
"\t\tPATTERN\n\n"
"\tArguments:\n"
"\tPATTERN\tPattern specifiying a help topic \n\n"
"\tExit Status: \n"
"\tReturns success unless PATTERN is not found or"
" an invalid option is given.\n";

static const char HELP_JOBS[] =
"jobs: jobs [-l]\n"
"\tDisplay status of jobs.\n\n"
"\tLists the active jobs.\n\n"
"\tOptions:\n"
"\t -l lists process IDs in addition to the normal information\n\n"
"\tExit Status: Returns success "
"unless an invalid option is given or an error occurs.\n";

static const char HELP_PWD[] =
"pwd: pwd\n"
"\tPrint the name of the current working directory.\n\n"
"\tExit Status:\n"
"\tReturns 0 unless an invalid option is given or the current directory\n"
"\tcannot be read.\n";

static const char HELP_REPEAT[] =
"repeat: repeat n command [arg ...]\n"
"\tRepeats a command n times\n\n"
"\tExit Status:\n"
"\tReturns the last return value of the command\n";

static const char HELP_SETENV[] =
"setenv: setenv [name [value]]\n"
"\tSets an environnement variable\n\n"
"\tSetenv adds the variable name to the environment with the value value,\n"
"\tif name does not already exist. If name does exist in the environment,\n"
"\tthen its value is changed to value.\n\n"
"\tExit Status:\n"
"\tReturns 0 unless name is invalid\n";

static const char HELP_TRUE[] =
"true: true\n"
"\tReturn a successful result.\n\n"
"\tExit Status:\n"
"\tAlways succeeds.\n";

static const char HELP_UNALIAS[] =
"unalias: unalias [-a] name [name ...]\n"
"\tRemove each NAME from the list of defined aliases.\n\n"
"\tOptions:\n"
"\t -a	remove all alias definitions\n\n"
"\tReturn success unless a NAME is not an existing alias.\n";

static const char HELP_UNSETENV[] =
"unsetenv: unsetenv [arg ...]\n"
"\tUnsets an environnement variable\n\n"
"\tUnsetenv deletes the variable name from the environment.\n"
"\tIf  name does not exist in the environment, then the function succeeds,\n"
"\tand the environment is unchanged.\n\n"
"\tExit Status:\n"
"\tReturns 0.\n";

static char const * const TAB_HELP[] = {
	"alias",
	"builtin",
	"cd",
	"echo",
	"env",
	"exit",
	"false",
	"fg",
	"help",
	"jobs",
	"pwd",
	"repeat",
	"setenv",
	"true",
	"unalias",
	"unsetenv"
};

#define HELP_ERROR(name)		\
printf("42sh: help: No help topic corresponds to `%s'.try with `help help'\n",\
	name)

static char const * const TAB_MSG[] = {
	HELP_ALIAS,
	HELP_BUILTIN,
	HELP_CD,
	HELP_ECHO,
	HELP_ENV,
	HELP_EXIT,
	HELP_FALSE,
	HELP_FG,
	HELP_HELP,
	HELP_JOBS,
	HELP_PWD,
	HELP_REPEAT,
	HELP_SETENV,
	HELP_TRUE,
	HELP_UNALIAS,
	HELP_UNSETENV
};

static const int NB_HELP = 16;

#endif
