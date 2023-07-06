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
# include <stdbool.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <readline/history.h>
# include <readline/readline.h>

enum e_type
{
	WORD,
	PIPE,
	SEMICOLON,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HERE_DOC,
	END
};

typedef struct s_env
{
	char			*key;
	char			*value; // malloc 0 and NULL are not the same

	struct s_env	*next;
}	t_env;

typedef struct s_arg
{
	char			*arg;
	int				type;
	struct s_arg	*right;
	struct s_arg	*left;
}	t_arg;

typedef struct s_data
{
	char	*user_input;
	t_arg *arg_list;
	int		status;
}   t_data;

//signals
void				stop_signals(void);
void				handle_sigint(void);
void				sig_handler(int signum);
void				sig_fork_handler(int signum);


//libft
int ft_strlen(char *str);

#endif