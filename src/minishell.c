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

void	minishell(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;

	t_minishell	shell;

	printf("estou dentro do src \n");
	while (1)
	{
		shell.line = readline("IMPRIMIR ALGO BONITO AQUI\n");
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

