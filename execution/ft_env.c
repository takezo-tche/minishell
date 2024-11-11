#include "../include/minishell.h"

void	ft_env(t_data *data)
{
	t_var	*current;

	current = data->var_data;
	while (current)
	{
		printf("%s=%s\n", current->key, current->value);
		current = current->next;
	}
}
