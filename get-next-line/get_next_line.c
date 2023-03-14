/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:44:02 by vparlak           #+#    #+#             */
/*   Updated: 2023/03/14 19:14:59 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}


char	*ft_strdup(const char *s1)
{
	size_t	len_s1;
	char	*dst;

	len_s1 = ft_strlen(s1) + 1;
	dst = (char *)malloc(len_s1);
	if (dst == NULL)
		return (dst);
	ft_strlcpy(dst, s1, len_s1);
	return (dst);
}

char	*get_next_line(int fd)
{
	char	*str;
	int		i;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == 10)
			break ;
		i++;
	}
	str = ft_strdup(buffer);
	return (str);
}

int	main(void)
{
	char	*path;
	int		fd;
	char	*str;

	path = "./text.txt";
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
}
