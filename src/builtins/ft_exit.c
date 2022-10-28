#include "../../minishell.h"

int	ft_exit(t_line *lst, char **cmd)
{
	int	status;

	if (cmd[1] && cmd[2])
	{
		perror("exit: too many arguments");
		return (1);
	}
	if (cmd[1])
	{
		status = ft_atoi(cmd[1]);
		lst_free(&lst);
		ft_str_free(cmd);
		clear_history();
		exit(status % 256);
	}
	else
	{
		clear_history();
		lst_free(&lst);
		ft_str_free(cmd);
		exit(0);
	}
	return (1);
}