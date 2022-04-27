#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
# include "../libraries/libft/src/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

 #define PATH_MAX 4096

# define CYAN "\001\033[0;36m\002"
# define DEFAULT "\001\e[0;39m\002"
# define BLUE(string) "\x1b[34m" string "\x1b[0m"
# define RED(string) "\x1b[31m" string "\x1b[0m"

typedef struct s_minishell
{
	char	*line;
}	t_minishell;

void	minishell(int argc, char *argv[], char *envp[]);

#endif
