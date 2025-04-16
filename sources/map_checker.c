/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:16:21 by guisanto          #+#    #+#             */
/*   Updated: 2025/04/16 17:10:47 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checker(t_game *game)
{
	if (!is_retangular(game->map) && is_wall(game->map)
		&& is_elements_and_valid(game))
			return (1);
	return (0);
}

static int	is_retangular(char **map)
{
	int	len;
	int	i;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

static int is_wall(char **map)
{
	int i;
	int j;
	int width;

	width = ft_strlen(map[0]);
	i = 0;
	while(map[0][i]) //primeira linha
		if (map[0][i++] != '1')
			return (0);
	i = 0;
	while(map[i])
		i++;
	i--;
	j = 0;
	while(map[i][j]) //ultima linha
		if (map[i][j++] != '1')
			return (0);
	i = 0;
	while(map[i]) //laterias
	{
		if (map[i][0] != '1' || map[i][width - 1 ] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	is_elements_and_valid(t_game *game)
{
	int i;
	int j;

	game->n_player = 0;
	game->n_exit = 0;
	game->n_colect = 0;

	i = 0;
	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->n_player++;
			else if (game->map[i][j] == 'E')
				game->n_exit++;
			else if (game->map[i][j] == 'C')
				game->n_colect++;
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	if (game->n_player != 1 || game->n_exit < 1 || game->n_colect < 1)
		return (0);
	return (1);
}
