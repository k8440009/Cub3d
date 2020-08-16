/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:58:41 by sungslee          #+#    #+#             */
/*   Updated: 2020/07/08 20:00:40 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		sizeof_split(char const *s, char c)
{
	int				status;
	size_t			cnt;

	status = 0;
	cnt = 0;
	while (*s)
	{
		if (status == 0 && *s != c)
		{
			status = 1;
			cnt++;
		}
		else if (status == 1 && *s == c)
			status = 0;
		s++;
	}
	return (cnt);
}

static int			str_to_split(char **dest, char const *s, char c)
{
	size_t		split_len;

	while (*s)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0')
			break ;
		split_len = 0;
		while (*(s + split_len) != c && *(s + split_len) != '\0')
			split_len++;
		if (!(*dest = (char *)malloc(split_len + 1)))
			return (0);
		ft_strlcpy(*dest, s, split_len + 1);
		dest++;
		s += split_len;
	}
	return (1);
}

static void			free_split(char **dest, size_t split_len)
{
	size_t i;

	i = 0 - 1;
	while (++i < split_len + 1)
		free(dest[i]);
	free(dest);
}

char				**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	split_len;

	if (s == NULL)
		return (NULL);
	split_len = sizeof_split(s, c);
	if (!(tab = (char **)ft_calloc(split_len + 1, sizeof(char *))))
		return (NULL);
	if (!(str_to_split(tab, s, c)))
	{
		free_split(tab, split_len);
		return (NULL);
	}
	return (tab);
}
