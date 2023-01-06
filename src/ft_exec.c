#include "../minishell.h"

static int	check_builtins(t_line *lst, char **cmd, char **envp)
{
	int	i;

	i = -1;
	if (!ft_strncmp("env", cmd[0], 3))
		i = ft_env(cmd, lst->envp);
	else if (!ft_strncmp("pwd", cmd[0], 3))
		i = ft_pwd(cmd);
	else if (!ft_strncmp("echo", cmd[0], 4))
		i = ft_echo(cmd);
	else if (!ft_strncmp("cd", cmd[0], 2))
		i = ft_cd(cmd);
	else if (!ft_strncmp("unset", cmd[0], 5))
		i = ft_unset(cmd, lst->envp);
	else if (!ft_strncmp("export", cmd[0], 6))
		i = ft_export(cmd, lst->envp);
	else if (!ft_strncmp("exit", cmd[0], 4))
		i = ft_exit(lst, cmd, envp);
	return (i);
}

void	ft_exec(t_line *lst, char **envp)
{
	t_arg	*tmp;
	char	**arr;
	int		ret_value;

	tmp = lst->head;
	while (tmp)
	{
		if (tmp->id == CMD)
		{
			arr = get_full_cmd(tmp);
			ret_value = check_builtins(lst, arr, envp);
			if (ret_value < 0)
				ret_value = exec_cmd(get_cmd_path(arr[0], envp), arr, envp);
			ft_str_free(arr);
			break ;
		}
		tmp = tmp->next;
	}
}
