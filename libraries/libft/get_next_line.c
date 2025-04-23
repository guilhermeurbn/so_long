/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:34:58 by guisanto          #+#    #+#             */
/*   Updated: 2025/04/23 20:11:40 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50
#endif

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*next_line;
	int			bytes_read;

	next_line = NULL;
	bytes_read = 1;
	while ((fd >= 0 && BUFFER_SIZE > 0) && bytes_read > 0)
	{
		if (buffer[0])
		{
			next_line = ft_strjoinn(next_line, buffer);
			if (!next_line)
				return (NULL);
			if (next_line[ft_strlenn(next_line) - 1] == '\n')
				break ;
		}
		else
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read < 0)
				return (free(next_line), NULL);
			buffer[bytes_read] = '\0';
		}
	}
	return (next_line);
}

int	ft_strlenn(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoinn(char *next_line, char *buffer)
{
	char	*dest;
	int		s1;
	int		s2;
	int		i;

	s1 = ft_strlenn(next_line);
	s2 = ft_strlenn(buffer);
	dest = malloc(s1 + s2 + 1);
	if (!dest)
		return (free(next_line), NULL);
	dest[s1 + s2] = '\0';
	i = -1;
	while (++i < s1)
		dest[i] = next_line[i];
	free(next_line);
	i = -1;
	while (++i < s2)
		dest[s1 + i] = buffer[i];
	i = -1;
	while (buffer[s2 + ++i])
		buffer[i] = buffer[s2 + i];
	buffer[i] = '\0';
	return (dest);
}
/* int main()
{
	int fd;
	char *next_line;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		perror ("error");
	while((next_line = get_next_line(fd)) != NULL )
	{
		printf("%s", next_line);
		free(next_line);
	}
	close(fd);
	return (0);
}*/
