#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	idx;
	size_t	cnt;

	cnt = 0;
	idx = 0;
	while (src[cnt])
		cnt++;
	if (size != 0)
	{
		while (src[idx] && idx < size - 1)
		{
			dest[idx] = src[idx];
			idx++;
		}
		dest[idx] = '\0';
	}
	return (cnt);
}