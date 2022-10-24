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
