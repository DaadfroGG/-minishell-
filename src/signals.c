/* ************************************************************************** */
/**//**//*   *//**//*   By: *//**//*   Created:   by *//*   Updated:   by *//**/
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint(void)
{
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handle_sigquit(void)
{
	dprintf(2, "Quit (core dumped)\n");
}

void	stop_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, &sig_fork_handler);
}

void	sig_fork_handler(int signum)
{
	if (signum == SIGINT)
	{
		handle_sigint();
	}
	if (signum == SIGQUIT)
	{
		handle_sigquit();
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		handle_sigint();
	}
}
