#ifndef SOURCE_H
# define SOURCE_H

# define EOF (-1)
# define ERRCHAR (0)
# define INIT_SRC_POS (-2)

typedef struct s_source
{
	char	*buffer;
	long	bufsize;
	long	curpos;
}	t_source;

void	unget_char(t_source *src);
char	next_char(t_source *src);
char	peak_char(t_source *src);
void	skip_white_space(t_source *src);

#endif

// buffer -> entrada de dados, texto completo
// tamanho -> tamanho do texto de entrada
// corpus -> posicao atual do caracter fonte
