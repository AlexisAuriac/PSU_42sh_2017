/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Splits a string recusively taking into account quotes and escape chars.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

static int get_len_word(const char *str)
{
	int len = 0;
	char quote;

	while (str[len] && (!in_str(str[len], SEPS) || ESCAPED(str, len))) {
		if (in_str(str[len], QUOTES)) {
			quote = str[len];
			do {
				++len;
			} while (str[len] != quote);
		}
		++len;
	}
	return (len);
}

static int dup_arg_in_quotes(const char *str, char *arg, int *arg_len)
{
	const char quote = str[0];
	int i = 1;

	while (str[i] != quote)
		arg[(*arg_len)++] = str[i++];
	return (i);
}

static char *dup_arg(const char *str, int len)
{
	char *arg = malloc(sizeof(char) * (len + 1));
	int real_len = 0;

	if (arg == NULL) {
		perror("malloc");
		return (NULL);
	}
	for (int i = 0 ; i < len ; ++i) {
		if (str[i] == '\\' && in_str(str[i + 1], SEPS)) {
			arg[real_len++] = str[++i];
		} else if (in_str(str[i], QUOTES) && !ESCAPED(str, i)) {
			i += dup_arg_in_quotes(str + i, arg, &real_len);
		} else if (!in_str(str[i], SEPS) || ESCAPED(str, i))
			arg[real_len++] = str[i];
	}
	arg[real_len] = '\0';
	return (arg);
}

static char **add_word(char **arr, const char *str, int len, int prof)
{
	arr[prof] = dup_arg(str, len);
	if (arr[prof] == NULL) {
		perror("malloc");
		for (int i = len ; arr[len] ; ++i)
			free(arr[i]);
		free(arr);
		return (NULL);
	}
	return (arr);
}

char **rec_split_words(const char *str, int prof)
{
	int len;
	char **arr = NULL;

	while (in_str(str[0], SEPS))
		++str;
	if (str[0] == '\0') {
		arr = malloc(sizeof(char *) * (prof + 1));
		if (arr == NULL)
			perror("malloc");
		else
			arr[prof] = NULL;
	} else {
		len = get_len_word(str);
		arr = rec_split_words(str + len, prof + 1);
		if (arr == NULL)
			return (NULL);
		arr = add_word(arr, str, len, prof);
	}
	return (arr);
}