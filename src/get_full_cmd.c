/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:22:43 by mcochin           #+#    #+#             */
/*   Updated: 2022/10/21 15:55:53 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**fill_cmd_arr(t_arg *cmd, char **arr)
{
	int		i;
	t_arg	*tmp;

	i = 0;
	tmp = cmd;
	arr[i] = ft_calloc(sizeof(char), ft_strlen(tmp->data) + 1);
	ft_strlcpy(arr[i], tmp->data, ft_strlen(tmp->data) + 1);
	if (!tmp->next)
		return (arr);
	tmp = tmp->next;
	i++;
	while (tmp && (tmp->id == ARG || tmp->id == LITERAL))
	{
		arr[i] = ft_calloc(sizeof(char), ft_strlen(tmp->data) + 1);
		ft_strlcpy(arr[i], tmp->data, ft_strlen(tmp->data) + 1);
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

char	**get_full_cmd(t_arg *cmd)
{
	int		i;
	char	**arr;
	t_arg	*tmp;	

	i = 1;
	tmp = cmd;
	if (cmd->id != CMD)
		return (NULL);
	while (tmp->next && (tmp->next->id == ARG || tmp->next->id == LITERAL))
	{
		tmp = tmp->next;
		i++;
	}
	arr = ft_calloc(sizeof(char *), i + 1);
	arr = fill_cmd_arr(cmd, arr);
	return (arr);
}
