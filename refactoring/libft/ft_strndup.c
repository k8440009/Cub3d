#include "libft.h"
char		*ft_strndup(const char *s, size_t n)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s);
	if (len > n)
		len = n;
	if (!(ptr = (char *)malloc(len + 1)))
		return (NULL);
	ptr[len] = '\0';
	return (ft_memcpy(ptr, s, len));
}