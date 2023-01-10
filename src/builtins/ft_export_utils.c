#include "../../minishell.h"

void	print_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		printf("declare -x %s\n", arr[i]);
		i++;
	}
}

char	**swap_w_next(char **arr, int i, int j)
{
	char	*tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
	return (arr);
}

void	print_env_alpha(t_envp *envp)
{
	char	**envp_arr;
	int		len;
	int		i;
	int		j;

	envp_arr = lst_to_arr(envp);
	i = 0;
	while (i < envp->length - 1)
	{
		j = i + 1;
		while (j < envp->length)
		{
			len = ft_strlen(envp_arr[i]);
			if (ft_strncmp(envp_arr[i], envp_arr[j], len) > 0)
				envp_arr = swap_w_next(envp_arr, i, j);
			j++;
		}
		i++;
	}
	print_arr(envp_arr);
	ft_str_free(envp_arr);
}
