
#include "../../libraries/libft/src/libft.h"
#define HASH_SIZE 100

typedef struct s_hash_elem
{
	char				*key;
	char				*data;
	struct s_hash_elem	*next;
}	t_hash_elem;

int	hash(const char *key)
{
	int	hash;

	hash = 0;
	while (*key)
	{
		hash += *key;
		hash = (hash * (*key)) % HASH_SIZE;
		key++;
	}
	return (hash);
}

t_hash_elem	*table_lookup(t_hash_elem **table, const char *key)
{
	t_hash_elem	*elem;

	elem = table[hash(key)];
	while (elem)
	{
		if (!ft_strncmp(elem->key, key, ft_strlen(elem->key)))
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}

void	insert_element(t_hash_elem **table, const char *key, const char *data)
{
	t_hash_elem	*elem;

	elem = table_lookup(table, key);
	if (elem)
	{
		free(elem->data);
		elem->data = ft_strdup(data);
	}
	else
	{
		elem = malloc(sizeof(t_hash_elem));
		if (!elem)
			return ;
		elem->key = ft_strdup(key);
		elem->data = ft_strdup(data);
		elem->next = table[hash(key)];
		table[hash(key)] = elem;
	}
}

t_hash_elem	*remove_element(t_hash_elem **table, const char *key)
{
	t_hash_elem	*elem;
	t_hash_elem	*prev;

	elem = table_lookup(table, key);
	if (!elem)
		return (NULL);
	prev = table[hash(key)];
	if (prev == elem)
	{
		table[hash(key)] = elem->next;
		return (elem);
	}
	else
	{
		while (prev->next != elem && prev->next)
			prev = prev->next;
		prev->next = elem->next;
		return (elem);
	}
	return (NULL);
}
