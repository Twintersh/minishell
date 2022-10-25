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

int	main(int argc, char **argv, char **envp)
{
	if (argc > 2 || !argv[1])
		return (0);
	main_exec(argv[1], envp);
	return (0);
}