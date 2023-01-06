#include "../../minishell.h"

int	ft_exit(t_line *lst, char **cmd, char **envp)
{
	unsigned char	status;

	if (cmd[1] && cmd[2])
	{
		perror("exit: too many arguments");
		return (1);
	}
	ft_str_free(envp);
	lst_env_free(&lst->envp);
	lst_free(&lst);
	clear_history();
	if (cmd[1])
	{
		status = (unsigned char)ft_atoi(cmd[1]);
		ft_str_free(cmd);
		exit(status);
	}
	else
	{
		ft_str_free(cmd);
		exit(0);
	}
	return (0);
}
