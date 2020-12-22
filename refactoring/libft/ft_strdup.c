#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	idx;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ptr == NULL)
		return (NULL);
	idx = -1;
	while (s[++idx])
		ptr[idx] = s[idx];
	ptr[idx] = '\0';
	return (ptr);
}