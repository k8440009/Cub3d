#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	idx;

	if (dest == 0 && src == 0)
		return (dest);
	idx = 0;
	d = (char *)dest;
	s = (char *)src;
	while (idx < n)
	{
		d[idx] = s[idx];
		idx++;
	}
	return (dest);
}