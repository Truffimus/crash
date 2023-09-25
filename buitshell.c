#include "shell.h"

/**
displayHistory - displays the command history list
@info: Structure containing potential arguments 
Return: Always returns 0 on success
*/
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
setAlias - sets an alias to a string format
@info: the parameter structure
@str: the string alias
Returns: 0 on success, 1 on error
*/
int unset_alias(info_t *info, char *str)
{
	char *j, k;
	int rett;

	j = _strchr(str, '=');
	if (!j)
		return (1);
	k= *j;
	*j = 0;
	rett = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*j = k;
	return (rett);
}

/**
setAlias - sets an alias to a string format
@info: the parameter structure
@str: the string alias
Returns: 0 on success, 1 if  error occurs
*/
int set_alias(info_t *info, char *str)
{
	char *a;

	a = _strchr(str, '=');
	if (!a)
		return (1);
	if (!*++a)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
printAlias - prints an alias string format  in the code
@node: alias node
Returns: 0 on success, 1 on error
*/
int print_alias(list_t *node)
{
	char *a = NULL, *h = NULL;

	if (node)
	{
		a = _strchr(node->str, '=');
		for (h = node->str; h<= a; h++)
		_putchar(*h);
		_putchar('\'');
		_puts(a + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
aliasCommand - mimics the behavior of the alias builtin command
@info: the structure containing arguments
Return: Always returns 0 on success
*/
int _myalias(info_t *info)
{
	int l = 0;
	char *b = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (l = 1; info->argv[l]; l++)
	{
		b = _strchr(info->argv[l], '=');
		if (b)
			set_alias(info, info->argv[l]);
		else
			print_alias(node_starts_with(info->alias, info->argv[l], '='));
	}

	return (0);
}
