#ifndef SOURCE_H
#define SOURCE_H

#define EOF (-1)
#define ERRCHAR (0)

#define INIT_SRC_POS (-2)

typedef struct s_source
{
    char *buffer; // -> linha recebida do CLI
    long bufsize; // -> tamanho da linha recebida
    long  curpos; // -> posicao atual que aponta no buffer
}	t_source;

// traz o proximo char e esquece o primeiro
char	next_char(t_source *src);
// recupera o ultimo caracter
void	unget_char(t_source *src);
// apenas olha o proximo char sem alterar
char	peek_char(t_source *src);
// pula os espacoes em banco numa string
void	skip_white_spaces(t_source *src);


#endif
