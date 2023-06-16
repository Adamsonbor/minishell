#include "../minishell.h"

int	ft_num_quotes(char *str)
{
	int	num;

	num = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
			num++;
		str++;
	}
	return (num);
}

char	*ft_delete_quotes(char *str)
{
	char	*tmp;
	char	*out;
	int		indx;
	int		len;

	len = ft_strlen(str) - ft_num_quotes(str) + 1;
	out = (char *)malloc(sizeof(char) * len);
	if (!out)
	{
		free (str);
		return (NULL);
	}
	indx = 0;
	tmp = str;
	while (*str)
	{
		if (*str != '\'' && *str != '\"')
			out[indx++] = *str;
		str++;
	}
	out[indx] = 0;
	free(tmp);
	return (out);
}
