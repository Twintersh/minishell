#include "../minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_envp	*envp_lst;

	envp_lst = lst_env_new();
	envp_lst = arr_to_lst(envp_lst, envp);
	if (argc > 1 || argv[1])
		return (0);
	while (1)
	{
		prompt(envp_lst);
	}
	return (0);
}

void	ft_str_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

int	exec_cmd(char *cmd, char **args, char **envp)
{
	pid_t	pid;
	int		ret_value;

	if (!cmd)
		return (1);
	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == CHILD)
		execve(cmd, args, envp);
	waitpid(pid, &ret_value, 0);
	free(cmd);
	return (ret_value);
}

void	main_exec(char *str, t_envp *envp)
{
	t_line	*line;
	char	**envp_arr;

	envp_arr = lst_to_arr(envp);
	line = lst_new(envp);
	parse(line, str);
	check_variables(line, envp_arr);
	lit_parse(line, envp_arr);
	ft_exec(line, envp_arr);
	ft_str_free(envp_arr);
	lst_free(&line);
}
