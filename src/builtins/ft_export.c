#include "../../minishell.h"

static int	parse_arg(char *cmd)
{
	int	i;

	i = 1;
	if (!ft_isalpha(cmd[0]) && cmd[0] != '_')
	{
		printf("export : `%s` : bad identifier\n", cmd);
		return (1);
	}
	while (cmd[i] && cmd[i] != '=')
	{
		if ((cmd[i] < 'A' && cmd[i] > 'Z') || (cmd[i] < 'a' && cmd[i] > 'z')
			|| cmd[i] == '_' || (cmd[i] < '1' && cmd[i] > '9'))
		{
			printf("export : %s : bad identifier\n", cmd);
			return (1);
		}
		i++;
	}
	return (0);
}

static char	**get_var(char *line)
{
	char	**var;
	int		i;

	i = 0;
	var = ft_calloc(sizeof(char *), 3);
	var[2] = NULL;
	while (line[i] && line[i] != '=')
		i++;
	i++;
	var[0] = ft_substr(line, 0, i - 1);
	var[1] = ft_substr(line, i, ft_strlen(line) - i);
	return (var);
}

static t_envp	*add_var(t_envp *envp, char **var)
{
	t_vars	*tmp;
	int		varlen;

	tmp = envp->head;
	varlen = ft_strlen(var[0]);
	while (tmp && ft_strncmp(var[0], tmp->var, varlen))
		tmp = tmp->next;
	if (tmp)
	{
		if (tmp->value)
			free(tmp->value);
		tmp->value = ft_strdup(var[1]);
	}
	else
		add_arg_tail_env(envp, ft_strdup(var[0]), ft_strdup(var[1]));
	return (envp);
}

int	ft_export(char **cmd, t_envp *envp)
{
	char	**var;
	int		i;
	int		status;

	i = 1;
	status = 0;
	if (!cmd[1])
	{
		ft_env(cmd, envp);
		return (0);
	}
	while (cmd[i])
	{
		status = parse_arg(cmd[i]);
		if (status == 0)
		{
			var = get_var(cmd[i]);
			add_var(envp, var);
			ft_str_free(var);
		}
		i++;
	}
	return (status);
}
