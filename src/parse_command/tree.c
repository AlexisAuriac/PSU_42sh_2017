/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Basic tree functions.
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "shell.h"

node_t *create_node(void)
{
	node_t *new_node = malloc(sizeof(node_t));

	if (new_node == NULL) {
		perror("malloc");
		return (NULL);
	}
	memset(new_node, 0, sizeof(node_t));
	new_node->op = EXPR;
	return (new_node);
}

bool create_branchs(node_t *node)
{
	node->left = create_node();
	if (node->left == NULL)
		return (false);
	node->right = create_node();
	if (node->right == NULL) {
		free(node->left);
		node->left = NULL;
		return (false);
	}
	return (true);
}

void del_tree(node_t *tree)
{
	if (tree->left != NULL)
		del_tree(tree->left);
	if (tree->right != NULL)
		del_tree(tree->right);
	if (tree->op == EXPR)
		my_free_array((void *) tree->expr);
	free(tree);
}

void show_tree(node_t *tree)
{
	if (tree == NULL)
		return;
	if (tree->op != EXPR) {
		printf("op: %s\n", TOKENS[tree->op]);
	} else {
		printf("expr: ");
		for (int i = 0 ; tree->expr[i] ; ++i) {
			printf("%s ", tree->expr[i]);
		}
		putchar('\n');
	}
	if (tree->left != NULL) {
		printf("left\n");
		show_tree(tree->left);
	}
	if (tree->right != NULL) {
		printf("right\n");
		show_tree(tree->right);
	}
}
