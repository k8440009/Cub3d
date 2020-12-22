  
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:21:29 by sungslee          #+#    #+#             */
/*   Updated: 2020/08/08 20:30:52 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int ft_strcmp(const char *s1, const char *s2);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_strlen(const char *s);
void *ft_memcpy(void *dest, const void *src, size_t n);

char **ft_split(char const *s, char c);
size_t ft_strlcpy(char *dest, const char *src, size_t size);
void *ft_calloc(size_t nmemb, size_t size);
void ft_bzero(void *s, size_t n);
void *ft_memset(void *b, int c, size_t n);
int ft_atoi(const char *str);
char *ft_strdup(const char *s);

#endif