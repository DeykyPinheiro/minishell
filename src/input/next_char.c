#include "input.h"

char	next_char(t_source *src)
{
	if (!src || !src->buffer)
		return (ERRCHAR);
	if (src->curpos == INIT_SRC_POS)
		src->curpos = -1;
	if (++src->curpos >= src->bufsize)
	{
		src->curpos = src->bufsize;
		return (EOF);
	}
	return (src->buffer[src->curpos]);
}
