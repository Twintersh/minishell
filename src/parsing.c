/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:45:59 by twinters          #+#    #+#             */
/*   Updated: 2022/10/18 18:23:48 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	prompt(char **envp)
{
	char	*str;

	(void)envp;
	str = NULL;
	str = readline("Minishell> ");
	if (*str)
	{
		add_history(str);
		main_exec(str);
	}
}

t_line	*parse(char *str)
{
	t_line	*line;
	int		i;

	i = 0;
	line = lst_new();
	while (str[i])
	{
		if (str[i] == '|')
			add_arg_tail(line, "|", PIPE);
		else if (str[i] == '>' || str[i] == '<')
		{
			if (str[i] == str[i + 1])
			{
				add_arg_tail(line, ft_substr(str, i, 2), REDIR);
				i++;
			}
			else
				add_arg_tail(line, ft_substr(str, i, 1), REDIR);
			
		}
		else if (str[i] == '"' || str[i] == '\'')
			i = get_quotes(line, str, i, str[i]);
		else if (str[i] != ' ' && str[i] != '>' && str[i] != '<')
			i = get_literal(line, str, i);
		i++;
	}
	return (line);
}

int get_quotes(t_line *line, char *str, int i, char c)
{
	int	j;

	i++;
	j = i;
	while (str[i])
	{
		if (str[i] == c)
		{
			add_arg_tail(line, ft_substr(str, j, i - j), LITERAL);
			return (i);
		}
		i++;
	}
	return (i);
}

int	get_literal(t_line *line, char *str, int i)
{
	int	j;
	
	j = i;
	while (str[i] && str[i] != ' ' && str[i] != '|' && str[i] != '>' && str[i] != '<'
		&& str[i] != '"' && str[i] != '\'')
		i++;
	add_arg_tail(line, ft_substr(str, j, i - j), LITERAL);
	return (i);
}

void	main_exec(char *str)
{
	t_line *line;

	line = parse(str);
	debug(line);
}

void debug(t_line *chibre)
{
	t_arg *tmp;

	tmp = chibre->head;
	while (tmp)
	{
		printf("id : %d | data : %s\n\n", tmp->id, tmp->data);
		tmp = tmp->next;
	}
}
