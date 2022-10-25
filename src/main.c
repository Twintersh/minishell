#include "../minishell.h"

// int	main(int argc, char **argv, char **envp)
// {
// 	if (argc > 1 || argv[1])
// 		return (0);
// 	while (1)
// 	{
// 		prompt(envp);
// 	}
// 	return (0);
// }

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

void	exec_cmd(char *cmd, char **args, char **envp)
{
	pid_t	pid;

	if (!cmd)
		return ((void)ft_putstr("Command not found\n"));
	pid = fork();
	if (pid < 0)
		return ;
	if (pid == CHILD)
		execve(cmd, args, envp);
	waitpid(pid, NULL, 0);
	free(cmd);
}

void	main_exec(char *str, char **envp)
{
	t_line	*line;

	line = lst_new(envp);
	parse(line, str);
	check_variables(line);
	lit_parse(line) ;
	// ft_exec(line);
	debug(line);
	lst_free(&line);
}
