#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
# include "../libraries/libft/src/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_minishell
{
	char	*line;
}	t_minishell;

void	minishell(int argc, char *argv[], char *envp[]);

#endif
