/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Checks if their aren't any unmatched quotes.
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "shell.h"

static int get_quote(const char *str, char *quote, int offset)
{
	int i = offset;

	*quote = '\0';
	while (str[i] && *quote == '\0') {
		for (int j = 0 ; QUOTES[j] ; ++j) {
			if (str[i] == QUOTES[j] && !ESCAPED(str, i))
				*quote = str[i];
		}
		++i;
	}
	return (i);
}

bool check_quotes(char *str)
{
	bool result = true;
	char quote;
	int i = 0;

	while (result && str[i]) {
		i = get_quote(str, &quote, i);
		if (quote) {
			while (str[i] != quote && str[i])
				++i;
			if (!str[i]) {
				ERROR_UNMATCHED_QUOTE(quote);
				result = false;
			} else
				++i;
		}
	}
	return (result);
}
