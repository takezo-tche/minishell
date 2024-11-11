#include "include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*line;

	(void)argc;
	(void)argv;
	init_env(&data, envp);
	while (1)
	{
		line = readline("minishell> ");
		if (!line)
			break ;
		add_history(line);
		//parsing(&data);
		if (strcmp(line, "env") == 0)
			ft_env(&data);
		free(line);
	}
	free_env_vars(&data);
	return (0);
}
