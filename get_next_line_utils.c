/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:08:01 by jole              #+#    #+#             */
/*   Updated: 2022/11/16 20:39:28 by jole             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	int		s1_len;
	int		s2_len;

	if (!s1)
		s1 = ft_strdup("");
	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_s = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new_s)
		return (0);
	ft_memcpy(new_s, s1, s1_len);
	ft_memcpy(new_s + s1_len, s2, s2_len);
	new_s[s1_len + s2_len] = '\0';
	free((void *)s1);
	free((void *)s2);
	return (new_s);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst2;
	char	*src2;

	if (!dst && !src)
		return (0);
	dst2 = dst;
	src2 = (char *)src;
	while (n)
	{
		n--;
		*dst2++ = *src2++;
	}
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	slen;

	slen = ft_strlen(src);
	if (dstsize)
	{
		dstsize--;
		while (dstsize && *src != 0)
		{
			dstsize--;
			*dst++ = *src++;
		}
		*dst = '\0';
	}
	return (slen);
}
