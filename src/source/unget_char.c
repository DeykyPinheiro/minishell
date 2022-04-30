#include "source.h"

void	unget_char(t_source *src)
{
	if (src->curpos < 0)
		return ;
	src->curpos--;
}
