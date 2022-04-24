#include "minishell.h"

int	is_valid_line(char *line)
{
	int		is_valid;
	char	*line_trim;

	is_valid = 1;
	line_trim = ft_strtrim(line, " ");
	if (ft_strlen(line_trim) == 0)
		is_valid = 0;
	free_ptr(&line_trim);
	return (is_valid);
}

void	minishell(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;

	char *line;

	while (1)
	{
		line = readline("imprimir uma linha bonita aqui\n");

		printf("estou dentro do src \n");
		printf("comprimento da linha: %ld\n", ft_strlen(line));
		if (!line)
			EXIT_SUCCESS;
		if (!is_valid_line(line))
		{
			free_ptr(&line);
			continue;
		}
		free_ptr(&line);
	}

}

