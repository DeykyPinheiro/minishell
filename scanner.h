#ifndef SCANNER_H
#define SCANNER_H

typedef struct s_token
{
	struct source_s *src;
	int text_len;
	char *text;
}	t_token;

extern struct t_token eof_token;

t_token	*tokenize(t_source *src);
void	free_token(t_token *tok);

#endif
