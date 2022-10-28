#include "../../minishell.h"

int	ft_env(char **cmd, char **envp)
{
	int	i;

	i = 0;
	if (cmd[1])
	{
		perror("env : too many arguments");
		return (1);
	}
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
	return (1);
}