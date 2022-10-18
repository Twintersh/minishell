/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_managing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:38:29 by twinters          #+#    #+#             */
/*   Updated: 2022/10/18 17:44:07 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_line	*lst_new(void)
{
	t_line	*new;

	new = malloc(sizeof(t_line));
	if (!new)
		exit(EXIT_FAILURE);
	new->length = 0;
	new->tail = NULL;
	new->head = NULL;
	return (new);
}

t_line	*add_arg_tail(t_line *list, char *data, int id)
{
	t_arg	*new;

	new = malloc(sizeof(t_arg));
	if (!new || !list)
		exit(EXIT_FAILURE);
	new->next = NULL;
	new->id = id;
	new->data = malloc(sizeof(char) * ft_strlen(data));
	new->data = data;
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
		free(tmp->data);
		tmp = tmp->next;
		free(del);
	}
	free(*lst);
	*lst = NULL;
}
