/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DEBUG.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <mcochin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:22:13 by twinters          #+#    #+#             */
/*   Updated: 2022/10/21 16:39:29 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	debug(t_line *chibre)
{
	t_arg	*tmp;

	tmp = chibre->head;
	while (tmp)
	{
		printf("id : %d | data : %s\n", tmp->id, tmp->data);
		tmp = tmp->next;
	}
}
