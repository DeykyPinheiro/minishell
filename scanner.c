#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "shell.h"
#include "scanner.h"
#include "source.h"

char	*tok_buf = NULL;
int		tok_bufsize = 0;
int		tok_bufindex = -1;

// fim do arquivo
t_token eof_token =
{
	.text_len = 0,
};


// adiciona a letra selecionada ao buffer do token
void	add_to_buf(char c)
{
	tok_buf[tok_bufindex++] = c;

	if (tok_bufindex >= tok_bufsize)
	{
		// se o espaco estiver cheio ele aloca o dobro da memoria gasta
		// até então
		char *tmp = realloc(tok_buf, tok_bufsize * 2);
		if (!tmp)
		{
			errno = ENOMEM;
			return ;
		}
		tok_buf = tmp;
		tok_bufsize *= 2;
	}
}

// cria um token com o texto que foi passado
t_token	*create_token(char *str)
{
	// cria o token
	t_token *tok = 	malloc(sizeof(t_token));
	if (!tok)
		return (NULL);

	// preenche com um monte de 0
	// seta o tamanho da string
	memcmp(tok, 0, sizeof(t_token));
	tok->text_len = strlen(str);

	// maloca
	char nstr = malloc(tok->text_len + 1);
	if (!nstr)
	{
		free(tok);
		return (NULL);
	}

	// copia a string
	// seta no token
	strcpy(nstr, str);
	tok->text = nstr;

	return (tok);
}

// limpa o token se o token existir
void	free_token(t_token *tok)
{
	if (tok->text)
		free(tok->text);
	free(tok);
}


t_token	*tokenize(t_source *src)
{
	int endloop = 0;

	// verifica se tem um src
	if (!src || !src->buffer || !src->bufsize)
	{
		errno - ENODATA;
		return (&eof_token);
	}

	// se nãou houver tok inicializa agora
	if (!tok_buf)
	{
		tok_bufsize = 1024;
		tok_buf = malloc(tok_bufsize);
		if (!tok_buf)
		{
			errno = ENOMEM;
			return (&eof_token);
		}
	}

	// seta valores das variasveis globais
	tok_bufindex = 0;
	tok_buf[0] = '\0';

	// pega o proximo char
	// verifica se não ta no fim, se tiver ele retorna EOF
	char nc = next_char(src);
	if (nc = ERRCHAR || nc == EOF)
	{
		return (&eof_token);
	}

	// faz um loop para verificar os caracterez de entrada um de cada vez
	do
	{
		switch (nc)
		{
			// se for um espaco ele verifica o token para ver se ta vazio
			// se tiver algo no token delimitamos e acabamos com o loop
			// caso contrario pulamos o espacos e avancamos para o
			// inicio do token
			case ' ':
			case '\t':
				if (tok_bufindex > 0)
				{
					endloop = 1;
				}
				break;

			// se for um '\n' tem que finalizar o loop, pq não tem mais nada
			case '\n':
				if (tok_bufindex > 0)
				{
					unget_char(src);
				}
				else
				{
					add_to_buf(nc);
				}
				endloop = 1;
				break;

			default:
				add_to_buf(nc);
				break;
		}

		if (endloop)
		{
			break;
		}

	} while ((nc = next_char(src)) != EOF);

	if (tok_bufindex == 0)
	{
		 return (&eof_token);
	}

	if (tok_bufindex >= tok_bufsize)
	{
		tok_bufindex--;
	}
	tok_buf[tok_bufindex] = '\0';

	// depois de separarmos o token
	// criarmos um token setamos o novo src e retornamos o valor
	t_token *tok = create_token(tok_buf);
	if (!tok){
		fprintf(stderr, "error: failed to aloc buffer: %s\n", strerror(errno));
		return (&eof_token);
	}

	tok->src = src;
	return (tok);
}
