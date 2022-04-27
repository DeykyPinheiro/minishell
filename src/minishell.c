#include "minishell.h"

int	is_valid_line(t_minishell *shell)
{
	int		is_valid;
	char	*line_trim;

	is_valid = 1;
	line_trim = ft_strtrim(shell->line, " ");
	if (ft_strlen(line_trim) == 0)
		is_valid = 0;
	printf("comprimento da linha: %ld\n", ft_strlen(line_trim));
	free_ptr(&line_trim);
	return (is_valid);
}

char *colorir_cwd(char *cwd)
{
	char *tmp;
	char *colored;

	tmp = ft_strjoin(CYAN, cwd);
	free(cwd);
	colored = ft_strjoin(tmp, DEFAULT"\n" RED("❯ "));
	free(tmp);
	return (colored);
}

char	*get_current_path()
{
	char	*cwd;

	cwd = ft_calloc(PATH_MAX, sizeof(char));
	if(!cwd)
	{
		printf("aviso de erro\n");
		return (NULL);
	}
	if(!getcwd(cwd, PATH_MAX))
	{
		printf("aviso de erro\n");
		return (NULL);
	}
	return(colorir_cwd(cwd));
}

void	minishell(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;

	t_minishell	shell;
	char		*cwd;
	while (1)
	{
		cwd = get_current_path();
		shell.line = readline(cwd);
		free(cwd);
		if (!shell.line)
			EXIT_SUCCESS;
		if (!is_valid_line(&shell))
		{
			free_ptr(&shell.line);
			continue;
		}
		free_ptr(&shell.line);
	}

}

