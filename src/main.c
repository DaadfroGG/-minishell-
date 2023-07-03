/* ************************************************************************** */
/**//**//*   *//**//*   By: *//**//*   Created:   by *//*   Updated:   by *//**/
/* ************************************************************************** */

#include "minishell.h"

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_input(t_data *data)
{
	data->user_input = readline("bash $>");
	if (!data->user_input)
		return (write(2, "exit\n", 5), 1);
	add_history(data->user_input);
	if (!ft_strlen(data->user_input))
		return (free(data->user_input), 2);
	return (0);
}

int	shell_routine(int ac, char **av, char **env, t_data *data)
{
	(void)ac;
	(void)av;
	(void)env;
	if (get_input(data))
		return (1);
	printf("%s\n", data->user_input);
	free(data->user_input);
	return (0);
}

int init_data(t_data *data)
{
	data->status = 0;
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_data	data[1];

	(void)ac;
	(void)av;
	(void)env;

	if (init_data(data))
		return (1);
	signal(SIGINT, &sig_handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
		if (shell_routine(ac, av, env, data))
			break ;
	return 0;
}
