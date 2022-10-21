/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DEBUG.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:22:13 by twinters          #+#    #+#             */
/*   Updated: 2022/10/21 10:26:37 by twinters         ###   ########.fr       */
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
