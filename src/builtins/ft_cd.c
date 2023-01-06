#include "../../minishell.h"

int	ft_cd(char **cmd)
{
	char	pwd[PATH_MAX];
	char	*path;

	if (!getcwd(pwd, sizeof(pwd)))
	{
		perror("cd: pwd");
		return (1);
	}
	path = add_path(pwd, cmd[1]);
	if (chdir(path))
		perror(cmd[1]);
	if (path)
		free(path);
	return (0);
}
