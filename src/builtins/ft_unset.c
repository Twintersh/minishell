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
	while (cmd[i])
	{
		if ((cmd[i] < 'A' && cmd[i] > 'Z') || (cmd[i] < 'a' && cmd[i] > 'z')
			|| cmd[i] == '_' || (cmd[i] < '1' && cmd[i] > '9') || cmd[i] == '=')
		{
			printf("export : %s : bad identifier\n", cmd);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_unset(char **cmd, t_envp *envp)
{
	t_vars	*tmp;
	int		i;
	int		status;
	int		varlen;

	i = 1;
	tmp = envp->head;
	status = 0;
	if (!cmd[1])
		return (1);
	while (cmd[i])
	{
		status = parse_arg(cmd[i]);
		if (status == 0)
		{
			varlen = ft_strlen(cmd[i]);
			while (tmp && ft_strncmp(cmd[i], tmp->var, varlen))
				tmp = tmp->next;
			if (tmp)
				ft_delone_envp(&envp->head, tmp);
		}
		i++;
	}
	return (status);
}
