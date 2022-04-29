
#include "../../libraries/libft/src/libft.h"

#define HASH_SIZE 100

typedef struct s_hash_elem
{
	char				*key;
	char				*data;
	struct s_hash_elem	*next;
}	t_hash_elem;

