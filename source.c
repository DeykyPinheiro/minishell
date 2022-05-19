#include <errno.h>
#include "shell.h"
#include "source.h"


// volta uma casa no scanner
void	unget_char(t_source *src)
{
	if (src->curpos < 0)
		return ;
	src->curpos --;

}

// olha a casa na frente do scanner e altera o src
char	next_char(t_source *src)
{
	// verifica erros
	if (!src || !src->buffer)
	{
		errno = ENODATA;
		return (ERRCHAR);
	}

	char c1 = 0;
	if (src->curpos == INIT_SRC_POS)
		src->curpos = -1;
	else
	{
		c1 = src->buffer[src->curpos];
	}

	// informa o fim da string
	if (++src->curpos == src->bufsize)
	{
		src->curpos = src->bufsize;
		return (EOF);
	}
	return (src->buffer[src->curpos]);
}

// funciona semelhante ao next_chat só que esse não altera o curpos
// traz o proximo sem alterar o src
char	peek_char(t_source *src)
{
	// verificando erros
	if (!src || !src->buffer)
	{
		errno = ENODATA;
		return (ERRCHAR);
	}

	// guardando a posicao atual
	long pos = src->curpos;

	if (pos == INIT_SRC_POS)
	{
		pos++;
	}
	pos++;

	if (pos  >= src->bufsize)
	{
		return (EOF);
	}
	// retornando a proxima posicao
	return (src->buffer[pos]);
}

// pula todos os espacoes em branco de uma string para facilitar a tokenizacao
void	skip_white_spaces(t_source *src)
{
	char c;

	if(!src || !src->buffer)
	{
		return;
	}

	while(((c = peek_char(src)) != EOF) && (c == ' ' || c == '\t'))
	{
		next_char(src);
	}
}
