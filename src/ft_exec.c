#include "../minishell.h"

void	ft_exec(t_line *lst)
{
	t_arg	*tmp;
	char	**arr;

	tmp = lst->head;
	while (tmp)
	{
		if (tmp->id == CMD)
		{
			arr = get_full_cmd(tmp);
			exec_cmd(get_cmd_path(arr[0], lst->envp), arr, lst->envp);
			ft_str_free(arr);
		}
		tmp = tmp->next;
	}
}