#include "../minishell.h"

static int	is_builtins(char *cmd)
{
	if (!ft_strncmp("env", cmd, 3))
		return (1);
	else if (!ft_strncmp("pwd", cmd, 3))
		return (1);
	else if (!ft_strncmp("echo", cmd, 4))
		return (1);
	else if (!ft_strncmp("cd", cmd, 2))
		return (1);
	else if (!ft_strncmp("unset", cmd, 5))
		return (1);
	else if (!ft_strncmp("export", cmd, 6))
		return (1);
	else if (!ft_strncmp("exit", cmd, 4))
		return (1);
	return (0);
}

static char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp("PATH=", envp[i], 4))
		i++;
	return (envp[i] + 5);
}

char	*add_path(char *path, char *cmd)
{
	char	*cmd_p;
	char	*buff;

	buff = ft_strjoin("/", cmd);
	cmd_p = ft_strjoin(path, buff);
	free(buff);
	return (cmd_p);
}

int	is_cmd(char *cmd, char **envp)
{
	char	*cmd_p;
	char	**path;
	int		i;

	i = 0;
	if (is_builtins(cmd) || !access(cmd, X_OK))
		return (1);
	if (*cmd == '/')
		return (0);
	path = ft_split(get_path(envp), ':');
	cmd_p = add_path(path[i], cmd);
	while (path[i] && access(cmd_p, F_OK))
	{
		free(cmd_p);
		cmd_p = add_path(path[i], cmd);
		i++;
	}
	free(cmd_p);
	if (path[i] == NULL)
	{
		ft_str_free(path);
		return (0);
	}
	ft_str_free(path);
	return (1);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	*cmd_p;
	char	**path;
	int		i;

	i = 0;
	if (!access(cmd, F_OK))
		return (ft_strjoin("", cmd));
	if (*cmd == '/')
		return (NULL);
	path = ft_split(get_path(envp) + 5, ':');
	cmd_p = add_path(path[i], cmd);
	while (path[i] && access(cmd_p, F_OK))
	{
		free(cmd_p);
		cmd_p = add_path(path[i], cmd);
		i++;
	}
	if (path[i] == NULL)
	{
		free(cmd_p);
		cmd_p = NULL;
	}
	ft_str_free(path);
	return (cmd_p);
}
