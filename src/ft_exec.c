#include "../minishell.h"

void	ft_exec(t_line *lst)
{
	t_arg	*tmp;

	tmp = lst->head;
	while (tmp)
	{
		if (tmp->id == CMD)
		{
			
		}
		tmp = tmp->next;
	}
}