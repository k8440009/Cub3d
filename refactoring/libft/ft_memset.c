#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char *cur;

	if (n == 0)
		return (b);
	cur = (unsigned char *)b;
	while (n > 0)
	{
		*cur = (unsigned char)c;
		cur++;
		n--;
	}
	return (b);
}