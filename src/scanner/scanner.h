#ifndef SCANNER_H
#define SCANNER_H

#include "../minishell.h"


typedef struct s_scanner
{
	t_source	*src;
	int			text_len;
	char		*text;
}	t_scanner;



#endif

// src -> input de dados, struct que defini cmd no usuario digitou no terminal
// text_len -> comprimento do token
// text -> texto do token

