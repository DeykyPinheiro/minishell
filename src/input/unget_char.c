#include "input.h"

void	unget_char(t_input *src)
{
	if (src->curpos < 0)
		return ;
	src->curpos--;
}
