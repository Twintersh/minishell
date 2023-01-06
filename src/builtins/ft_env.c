#include "../../minishell.h"

int	ft_env(char **cmd, t_envp *envp)
{
	t_vars	*tmp;

	tmp = envp->head;
	if (cmd[1])
	{
		perror("env : too many arguments");
		return (1);
	}
	while (tmp)
	{
		printf("%s=%s\n", tmp->var, tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
