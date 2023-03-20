/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:21:14 by vparlak           #+#    #+#             */
/*   Updated: 2023/03/20 23:42:01 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
// buffer kadar oku n line görüce bastır geri kalanı sub str il yeni bufferı ayarla bastırdğın kadarını yazdır tekrar

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++ != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	len_str;

	len_str = ft_strlen(s);
	if (start >= len_str)
	{
		dst = (char *)malloc(sizeof(char));
		if (!dst)
			return (NULL);
		*dst = '\0';
	}
	else
	{
		if ((len_str - start) < len)
			len = len_str - start;
		if (len_str >= len)
			dst = (char *)malloc(len + 1);
		else
			dst = (char *)malloc(len_str + 1);
		if (dst == NULL)
			return (NULL);
		ft_strlcpy(dst, s + start, len + 1);
	}
	return (dst);
}

char	*ft_divide_lines(char *buffer)
{
	char	*str;
	int		i;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	str = ft_substr(buffer, 0, i + 1);
	return (str);
}

char	*ft_reader(int fd, char *str)
{
	char	*buffer;
	int		i;
	int		is_first;

	buffer = malloc(BUFFER_SIZE + 1);
	i = 1;
	is_first = 1;
	while (i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		if (is_first && i)
		{
			is_first = 0;
			str = ft_strdup(buffer);
		}
		else
			str = ft_strjoin(str, buffer);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	buffer = ft_reader(fd, buffer);
	line = ft_divide_lines(buffer);
	buffer = ft_substr(buffer, ft_strlen(line), ft_strlen(buffer));
	return (line);
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
	fflush(stdout);
	free(str);
}
