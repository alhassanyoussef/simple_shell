#include "shell.h"

/**
 * _myhis - displays the history list,
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int _myhis(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_ali - sets alias to string
 * @info: parameter struct
 * @st: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_ali(info_t *info, char *st)
{
	char *x, c;
	int rex;

	x = _strchr(st, '=');
	if (!x)
		return (1);
	c = *x;
	*x = 0;
	rex = delete_node_at_index(&(inf->alias),
		get_node_index(inf->alias, node_starts_with(inf->alias, st, -1)));
	*x = c;
	return (rex);
}

/**
 * set_ali - sets alias to string
 * @info: parameter struct
 * @st: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_ali(info_t *info, char *st)
{
	char *x;

	x = _strchr(st, '=');
	if (!x)
		return (1);
	if (!*++x)
		return (unset_alias(info, st));

	unset_alias(info, st);
	return (add_node_end(&(info->alias), st, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
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
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

