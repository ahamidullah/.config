#include <stddef.h>

void
memset(void *p, int val, size_t nbytes)
{
	size_t i;
	for (i = 0; i < nbytes; i++) {
		((char *)p)[i] = val;
	}
}

size_t
strlen(const char* str)
{
	size_t ret = 0;
	while ( str[ret] != 0 )
		ret++;
	return ret;
}
