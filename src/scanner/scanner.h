#ifndef SCANNER_H
#define SCANNER_H

#include "../minishell.h"


typedef struct s_token
{
	t_input		*src;
	int			text_len;
	char		*text;
}	t_token;

typedef struct s_scanner
{
	char	*tok_buf;
	int		tok_bufsize;
	int		tok_bufindex;
}	t_scanner;


void	add_to_buf(t_scanner *scanner, char c);


#endif

// src -> input de dados, struct que defini cmd no usuario digitou no terminal
// text_len -> comprimento do token
// text -> texto do token

