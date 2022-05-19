#ifndef SCANNER_H
#define SCANNER_H

# include "source.h"

typedef struct s_token
{
	t_source *src; // -> struct de entranda de dados
	int text_len; // -> tamanho do token
	char *text; // -> texto do token
}	t_token;

extern t_token eof_token;

// retonar um token ja com alguns tratamentos
t_token	*tokenize(t_source *src);
// limpa o token
void	free_token(t_token *tok);
// executa e trato o comando
int parse_and_execute(t_source *src);

#endif
