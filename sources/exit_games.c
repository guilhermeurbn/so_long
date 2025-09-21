/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_games.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:23:24 by guisanto          #+#    #+#             */
/*   Updated: 2025/09/18 14:08:38 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	exit_game(t_game *game)
{
	if (game)
	{
		if (game->map)
			free_map(game->map);
		if (game->mlx)
		{
			if (game->img_backg)
				mlx_destroy_image(game->mlx, game->img_backg);
			if (game->img_wall)
				mlx_destroy_image(game->mlx, game->img_wall);
			if (game->img_player)
				mlx_destroy_image(game->mlx, game->img_player);
			if (game->img_colect)
				mlx_destroy_image(game->mlx, game->img_colect);
			if (game->img_exit)
				mlx_destroy_image(game->mlx, game->img_exit);
			if (game->win)
				mlx_destroy_window(game->mlx, game->win);
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
	}
	exit(0);
}
