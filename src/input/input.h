#ifndef INPUT_H
# define INPUT_H

# define EOF (-1)
# define ERRCHAR (0)
# define INIT_SRC_POS (-2)

typedef struct s_input
{
	char	*buffer;
	long	bufsize;
	long	curpos;
}	t_input;

void	unget_char(t_input *src);
char	next_char(t_input *src);
char	peak_char(t_input *src);
void	skip_white_space(t_input *src);

#endif

// buffer -> entrada de dados, texto completo
// tamanho -> tamanho do texto de entrada
// corpus -> posicao atual do caracter fonte
