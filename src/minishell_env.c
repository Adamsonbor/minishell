#include "../minishell.h"

char *ft_get_env_value_by_name(t_shell *shell, char *str)
{
	char *tmp;
	char *out;

	tmp = ft_substr(str,  0, ft_len_word(str));
	out = ft_get_env_value(shell, tmp);
	free(tmp);
	return (out);
}


char *ft_get_env_value(t_shell *shell, char *var)
{
	t_env *tmp;

	tmp = shell->env;
	while (tmp && ft_strncmp(tmp->key, var, ft_strlen(var) + 1) != 0)
		tmp = tmp->next;
	if (!tmp)
		return(ft_strdup(""));
	return (ft_strdup(tmp->value));
}
