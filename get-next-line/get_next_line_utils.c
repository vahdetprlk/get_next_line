/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:59:54 by vparlak           #+#    #+#             */
/*   Updated: 2023/03/20 20:14:21 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	d = (char *)dst;
	s = (const char *)src;
	if (!d && !s)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len;

	len_src = ft_strlen(src);
	if (dstsize)
	{
		if (len_src >= dstsize)
			len = dstsize - 1;
		else
			len = len_src;
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (len_src);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (dstsize <= len_dst)
		return (dstsize + len_src);
	dst += len_dst;
	ft_strlcpy(dst, src, (dstsize - len_dst));
	return (len_src + len_dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	dstsize;

	dstsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *)malloc(dstsize);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s1, dstsize);
	ft_strlcat(dst, s2, dstsize);
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	dstsize;

	dstsize = ft_strlen(s1) + 1;
	dst = (char *)malloc(dstsize);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s1, dstsize);
	return (dst);
}
