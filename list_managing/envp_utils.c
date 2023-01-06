#include "../minishell.h"

static char	*get_var(char *str)
{
	char	*var;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	var = ft_calloc(sizeof(char), i + 1);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		var[i] = str[i];
		i++;
	}
	return (var);
}

static char	*get_value(char *str)
{
	char	*value;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '=')
		i++;
	value = ft_calloc(sizeof(char), (ft_strlen(str) - i));
	i++;
	while (str[i])
	{
		value[j] = str[i];
		j++;
		i++;
	}
	value[j] = '\0';
	return (value);
}

t_envp	*arr_to_lst(t_envp *lst, char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		lst = add_arg_tail_env(lst, get_var(arr[i]), get_value(arr[i]));
		i++;
	}
	return (lst);
}

char	**lst_to_arr(t_envp *envp_lst)
{
	char	**envp_arr;
	t_vars	*tmp;
	int		i;

	i = 0;
	tmp = envp_lst->head;
	envp_arr = ft_calloc(sizeof(char *), envp_lst->length + 1);
	while (tmp)
	{
		envp_arr[i] = ft_strjoinjoin(tmp->var, "=", tmp->value);
		tmp = tmp->next;
		i++;
	}
	envp_arr[i] = NULL;
	return (envp_arr);
}
