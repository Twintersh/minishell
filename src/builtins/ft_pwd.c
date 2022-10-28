#include "../../minishell.h"

int	ft_pwd(char **cmd)
{
	char	pwd[PATH_MAX];

	printf("oui\n");
	if (cmd[1])
	{
		perror("pwd: too many arguments\n");
		return (1);
	}
	if (!getcwd(pwd, sizeof(pwd)))
	{
		perror("pwd");
		return (1);
	}
	else
		printf("%s\n", pwd);
	return (1);
}