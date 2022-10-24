#include "../minishell.h"

t_line	*lst_new(char **envp)
{
	t_line	*new;

	new = malloc(sizeof(t_line));
	if (!new)
		exit(EXIT_FAILURE);
	new->envp = envp;
	new->length = 0;
	new->tail = NULL;
	new->head = NULL;
	return (new);
}

t_line	*add_arg_tail(t_line *list, char *str, int id)
{
	t_arg	*new;

	if (!*str)
		return (NULL);
	new = malloc(sizeof(t_arg));
	if (!new || !list)
		exit(EXIT_FAILURE);
	new->next = NULL;
	new->id = id;
	new->data = str;
	if (list->tail != NULL)
	{
		list->tail->next = new;
		new->prev = list->tail;
		list->tail = new;
	}
	else
	{
		list->tail = new;
		list->head = new;
		new->prev = NULL;
	}
	list->length++;
	return (list);
}

void	lst_free(t_line **lst)
{
	t_arg	*tmp;
	t_arg	*del;

	if (*lst == NULL)
		return ;
	tmp = (*lst)->head;
	while (tmp)
	{
		del = tmp;
		if (del->data)
			free(del->data);
		tmp = tmp->next;
		free(del);
	}
	free(*lst);
	*lst = NULL;
}
