#include "../minishell.h"

int	check_struct(t_line *line)
{
 	t_arg	*tmp;
	int		cmd;
	int		return_value;

	tmp = line->head;
	cmd = 0;
	while (tmp)
	{
		if (tmp->id == CMD)
			cmd++;
		if (tmp->id == PIPE)
			cmd = 0;
		if (cmd > 1)
			tmp->id = LITERAL;
		tmp = tmp->next;
	}
	return_value = check_pipes(line);
	return (return_value);
}

int	check_pipes(t_line *line)
{
	t_arg	*tmp;
	int		pipe;

	tmp = line->head;
	pipe = 1;
	while (tmp)
	{
		if (tmp->id == CMD)
			pipe--;
		if (tmp->id == PIPE)
			pipe++;
		tmp = tmp->next;
	}
	if (pipe)
		return (0);
	return (1);
}