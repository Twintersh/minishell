#include "../minishell.h"

int	get_nb_quotes(char *data)
{
	int	i;
	int	j;
	int	quote;

	i = 0;
	j = 0;
	quote = 0;
	while (data[i])
	{
		if (quote == data[i])
			quote = 0;
		if (!quote && (data[i] == '"' || data[i] == '\''))
		{
			j++;
			quote = data[i];
		}
		i++;
	}
	return (j);
}

static char	*fill_without_quotes(char *data, char *dest)
{
	int	j;
	int	i;
	int	quote;

	i = 0;
	j = 0;
	quote = 0;
	while (data[i])
	{
		if (quote == data[i])
			quote = 0;
		if (quote || (!quote && !(data[i] == '"' || data[i] == '\'')))
		{
			dest[j] = data[i];
			j++;
		}
		if (!quote && (data[i] == '\'' || data[i] == '"'))
			quote = data[i];
		i++;
	}
	return (dest);
}

char	*remove_quotes(char *data)
{
	char	*dest;
	int		nb_quotes;

	nb_quotes = get_nb_quotes(data);
	if (nb_quotes == 0)
		return (data);
	if ((nb_quotes % 2) == 1)
		return (NULL);
	dest = ft_calloc(sizeof(char), ft_strlen(data) + 1 - nb_quotes);
	dest = fill_without_quotes(data, dest);
	free(data);
	return (dest);
}
