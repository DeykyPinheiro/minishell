#include "scanner.h"

void	add_to_buf(t_scanner *scanner, char c)
{
	char	*tmp;

	scanner->tok_buf[scanner->tok_bufindex++] = c;
	if (scanner->tok_bufindex >= scanner->tok_bufsize)
	{
		tmp = ft_realloc(scanner->tok_buf, \
		scanner->tok_bufsize, scanner->tok_bufsize * 2);
	}
	if (!tmp)
		return ;
	scanner->tok_buf = tmp;
	scanner->tok_bufsize *= 2;
}
