#include "../../minishell.h"

int	ft_echo(char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i])
	{
		printf("%s", cmd[i]);
		i++;
		if (cmd[i])
			printf(" ");
	}
	printf("\n");
	return (1);
}
