/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:33:43 by twinters          #+#    #+#             */
/*   Updated: 2022/10/06 11:20:33 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	char	**cmd;

	if (argc > 1 || argv[1])
		return (0);
	while (1)
	{
		str = readline("Minishell> ");
		add_history(str);
		cmd = ft_split(str, ' ');
		exec_cmd(get_cmd_path(cmd[0], envp), cmd, envp);
		free(str);
		ft_str_free(cmd);
	}
	return (0);
}
