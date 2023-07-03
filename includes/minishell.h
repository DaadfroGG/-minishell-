/* ************************************************************************** */
/**//**//*   *//**//*   By: *//**//*   Created:   by *//*   Updated:   by *//**/
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <readline/history.h>
# include <readline/readline.h>


typedef struct s_data
{
	char	*user_input;
	int		status;
}   t_data;

void				stop_signals(void);
void				handle_sigint(void);
void				sig_handler(int signum);
void				sig_fork_handler(int signum);
#endif