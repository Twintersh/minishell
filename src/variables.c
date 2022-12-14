#include "../minishell.h"

static char	*crop_var(char *str)
{
	int		i;
	int		j;
	char	*var;

	i = 0;
	j = 0;
	while (str[i] && !(str[i] == ' ' || str[i] == '$'
			|| str[i] == '"' || str[i] == '<' || str[i] == '>'
			||str[i] == '|' || str[i] == '\''))
		i++;
	var = malloc(sizeof(char) * (i + 2));
	while (j < i)
	{
		var[j] = str[j];
		j++;
	}
	var[j] = '=';
	var[j + 1] = '\0';
	return (var);
}

static char	*get_var(char **envp, char *var)
{
	int		i;
	int		varlen;

	i = 0;
	varlen = ft_strlen(var);
	while (envp[i] && ft_strncmp(var, envp[i], varlen))
		i++;
	if (!envp[i])
		return (NULL);
	return (envp[i] + varlen);
}

char	*ft_strjoinjoin(char *start, char *mid, char *end)
{
	char	*tmp;
	char	*new;

	tmp = ft_strjoin(start, mid);
	new = ft_strjoin(tmp, end);
	free(tmp);
	return (new);
}

char	*change_variable(char *str, int i, char **envp)
{
	char	*start;
	char	*mid;
	char	*end;
	char	*var;

	var = crop_var(str + i + 1);
	start = ft_substr(str, 0, i);
	mid = get_var(envp, var);
	end = ft_strdup(str + i + ft_strlen(var));
	free(var);
	free(str);
	if (mid)
		str = ft_strjoinjoin(start, mid, end);
	else
		str = ft_strjoin(start, end);
	free(start);
	free(end);
	return (str);
}

void	check_variables(t_line *line, char **envp)
{
	t_arg	*arg;
	int		i;
	int		quote;

	arg = line->head;
	quote = 0;
	while (arg)
	{
		if (arg->id == LITERAL)
		{
			i = 0;
			while (arg->data[i])
			{
				if (!quote && arg->data[i] == '$')
					arg->data = change_variable(arg->data, i, envp);
				else if (!quote && (arg->data[i] == '\''))
					quote = arg->data[i];
				else if (quote == arg->data[i])
					quote = 0;
				i++;
			}
		}
		arg = arg->next;
	}
}
