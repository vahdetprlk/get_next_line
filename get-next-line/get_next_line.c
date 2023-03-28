/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:25:39 by vparlak           #+#    #+#             */
/*   Updated: 2023/03/21 23:52:36 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}

int	main(void)
{
	char	*path;
	int		fd;
	char	*str;

	path = "./test.txt";
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	fflush(stdout);
	str = get_next_line(fd);
	printf("%s", str);
	fflush(stdout);
		str = get_next_line(fd);
	printf("%s", str);
	fflush(stdout);
		str = get_next_line(fd);
	printf("%s", str);
	fflush(stdout);
		str = get_next_line(fd);
	printf("%s", str);
	fflush(stdout);
		str = get_next_line(fd);
	printf("%s", str);
	fflush(stdout);
		str = get_next_line(fd);
	printf("%s", str);
	fflush(stdout);
	free(str);
}
