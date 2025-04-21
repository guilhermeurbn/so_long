/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:03:42 by guisanto          #+#    #+#             */
/*   Updated: 2025/04/21 12:39:29 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **read_map(char *path)
{
	int fd;
	char *line;
	char *holder_map;
	char *holder;
	char **map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	holder = ft_strdup("");
	while (1)
{
	line = get_next_line(fd);
	if (!line)
		break;
	holder_map = ft_strjoin(holder, line);
	free(holder);
	free(line);
	holder = holder_map;
}
	map = ft_split(holder_map, '\n');
	free(holder_map);
	close(fd);
	return (map);
}
