/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:08:01 by jole              #+#    #+#             */
/*   Updated: 2022/11/21 17:57:11 by jole             ###   ########.fr       */
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

char	*ft_strjoin(t_list *list, char const *s2, int s2_len)
{
	char	*new_s;

	if (!list->surplus)
	{
		list->surplus = ft_strdup("");
		list->beginning = list->surplus;
	}
	if (list->surplus == 0 || s2 == 0)
		return (0);
	new_s = malloc((list->total_len + s2_len + 1) * sizeof(char));
	if (!new_s)
		return (0);
	ft_memcpy(new_s, list->surplus, list->total_len);
	ft_memcpy(new_s + list->total_len, s2, s2_len);
	new_s[list->total_len + s2_len] = '\0';
	free((void *)list->beginning);
	list->i = 0;
	if (s2)
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
