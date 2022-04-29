

#define HASH_SIZE 100

int hash (const char *key)
{
	int hash;
	int c;

	hash = 0;
	while (*key)
	{
		c = *key++;
		hash += c;
	}
	return (hash % HASH_SIZE);
}
