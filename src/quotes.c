#include "../minishell.h"

int	get_quotes(char *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data[i])
	{
		if (data[i] == '"' || data[i] == '\'')
			j++;
		i++;
	}
	return (j);
}

static char	*fill_wtquotes(char *data, char *dest)
{
	int	j;
	int	i;
	int	quote;

	i = 0;
	j = 0;
	quote = 0;
	while (data[i])
	{
		printf("%d\n", quote);
		if (quote || (!quote && !(data[i] == '"' || data[i] == '\'')))
		{
			dest[j] = data[i];
			j++;
		}
		if (!quote && (data[i] == '\'' || data[i] == '"'))
			quote = data[i];
		if (quote == data[i])
			quote = 0;
		i++;
	}
	return (dest);
}

char	*remove_quotes(char *data)
{
	char	*dest;
	int		i;

	i = get_quotes(data);
	if (i == 0)
		return (data);
	if ((i % 2) == 1)
		return (NULL);
	dest = ft_calloc(sizeof(char), ft_strlen(data) + 1 - i);
	dest = fill_wtquotes(data, dest);
	free(data);
	return (dest);
}