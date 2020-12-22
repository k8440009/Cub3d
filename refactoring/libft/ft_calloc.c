#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!(ptr = (void *)malloc(nmemb * size)))
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}