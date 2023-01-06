#include "../minishell.h"

t_envp	*lst_env_new(void)
{
	t_envp	*new;

	new = malloc(sizeof(t_envp));
	if (!new)
		exit(EXIT_FAILURE);
	new->length = 0;
	new->tail = NULL;
	new->head = NULL;
	return (new);
}

void	ft_delone_envp(t_vars **head, t_vars *del)
{
	if (*head == NULL || del == NULL)
		return ;
	if (*head == del)
		*head = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	if (del->var)
		free(del->var);
	if (del->value)
		free(del->value);
	free(del);
	return ;
}

t_envp	*add_arg_tail_env(t_envp *envp, char *var, char *value)
{
	t_vars	*new;

	new = malloc(sizeof(t_vars));
	if (!new || !envp)
		exit(EXIT_FAILURE);
	new->next = NULL;
	new->var = var;
	new->value = value;
	if (envp->tail != NULL)
	{
		envp->tail->next = new;
		new->prev = envp->tail;
		envp->tail = new;
	}
	else
	{
		envp->tail = new;
		envp->head = new;
		new->prev = NULL;
	}
	envp->length++;
	return (envp);
}

void	lst_env_free(t_envp **envp)
{
	t_vars	*tmp;
	t_vars	*del;

	if (*envp == NULL)
		return ;
	tmp = (*envp)->head;
	while (tmp)
	{
		del = tmp;
		if (del->value)
			free(del->value);
		if (del->var)
			free(del->var);
		tmp = tmp->next;
		free(del);
	}
	free(*envp);
	*envp = NULL;
}
