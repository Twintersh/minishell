/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:45:59 by twinters          #+#    #+#             */
/*   Updated: 2022/10/19 16:13:45 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	prompt(char **envp)
{
	char	*str;

	str = NULL;
	str = readline("Minishell> ");
	if (*str)
	{
		add_history(str);
		if (!ft_strncmp(str, "exit", 5))
			exit(EXIT_SUCCESS);
		main_exec(str, envp);
	}
}

void	parse(t_line *line, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			add_arg_tail(line, ft_substr(str, i, 1), PIPE);
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
}

void	lit_parse(t_line *line)
{
	t_arg	*tmp;

	tmp = line->head;
	while (tmp)
	{
		if (tmp->id % 10 == LITERAL)
		{
			if (tmp->data[0] == '-' && tmp->prev && 
				(tmp->prev->id == CMD || tmp->prev->id == ARG))
				tmp->id = ARG;
			else if (is_cmd(tmp->data, line->envp)
				&& (!tmp->prev || (tmp->prev && tmp->prev->id != REDIR)))
				tmp->id = CMD;
		}
		tmp = tmp->next;
	}
}

int	get_quotes(t_line *line, char *str, int i, char c)
{
	int	j;
	int tag;

	i++;
	j = i;
	tag = LITERAL;
	if (c == '\'')
		tag += DQUOTE;
	while (str[i])
	{
		if (str[i] == c)
		{
			add_arg_tail(line, ft_substr(str, j, i - j), tag);
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
	while (str[i] && str[i] != ' ' && str[i] != '|' && str[i] != '>'
		&& str[i] != '<' && str[i] != '"' && str[i] != '\'')
		i++;
	add_arg_tail(line, ft_substr(str, j, i - j), LITERAL);
	return (i);
}

void	main_exec(char *str, char **envp)
{
	t_line	*line;

	line = lst_new(envp);
	parse(line, str);
	lit_parse(line);
	debug(line);
	lst_free(&line);
}

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
