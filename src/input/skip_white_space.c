#include "input.h"

void	skip_white_space(t_source *src)
{
	char	c;

	if (!src || !src->buffer)
		return ;
	c = peak_char(src);
	while ((c != EOF) && (c == ' ' || c == '\t'))
		next_char(src);
}
