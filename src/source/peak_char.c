#include "source.h"

char	peak_char(t_source *src)
{
	long	pos;

	if (!src || !src->buffer)
		return (ERRCHAR);
	pos = src->curpos;
	if (pos == INIT_SRC_POS)
		pos++;
	if (++pos >= src->bufsize)
		return (EOF);
	return (src->buffer[pos]);
}
