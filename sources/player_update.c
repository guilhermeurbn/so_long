/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:51:06 by igvaz-fe          #+#    #+#             */
/*   Updated: 2025/09/22 14:00:39 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_update_image(char key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	if (key == 'w')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"images/iron_man1.xpm", &game->img_w, &game->img_h);
	else if (key == 's')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"images/iron_man2.xpm", &game->img_w, &game->img_h);
	else if (key == 'd')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"images/iron_man2.xpm", &game->img_w, &game->img_h);
	else if (key == 'a')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"images/iron_man1.xpm", &game->img_w, &game->img_h);
}

static int	player_reached_exit(t_game *game, char key)
{
	if (game->map[game->y_player][game->x_player] == 'E' && game->n_colect == 0)
	{
		if (key == 'w')
			game->map[game->y_player + 1][game->x_player] = '0';
		else if (key == 's')
			game->map[game->y_player - 1][game->x_player] = '0';
		else if (key == 'd')
			game->map[game->y_player][game->x_player - 1] = '0';
		else if (key == 'a')
			game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		game->endgame = 1;
		exit_game(game);
		map_draw(game);	
		return (1);
	}
	return (0);
}

static int	player_hit_wall(t_game *game, char key)
{
	if (game->map[game->y_player][game->x_player] == '1')
	{
		if (key == 'w')
			game->y_player += 1;
		else if (key == 's')
			game->y_player -= 1;
		else if (key == 'd')
			game->x_player -= 1;
		else if (key == 'a')
			game->x_player += 1;
		return (1);
	}
	return (0);
}

static int	player_exit(t_game *game, char key)
{
	if (player_reached_exit(game, key))
		return (1);
	if (player_hit_wall(game, key))
		return (1);
	return (0);
}

void	player_move(t_game *game, char key)
{
	player_update_image(key, game);
	if (player_exit(game, key))
		return ;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		if (game->map[game->y_player][game->x_player] != 'E')
			game->map[game->y_player][game->x_player] = 'P';
		if (key == 'w' && game->map[game->y_player + 1][game->x_player] != 'E')
			game->map[game->y_player + 1][game->x_player] = '0';
		else if (key == 's' && game->map[game->y_player
				- 1][game->x_player] != 'E')
			game->map[game->y_player - 1][game->x_player] = '0';
		else if (key == 'd' && game->map[game->y_player][game->x_player
			- 1] != 'E')
			game->map[game->y_player][game->x_player - 1] = '0';
		else if (key == 'a' && game->map[game->y_player][game->x_player
			+ 1] != 'E')
			game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		map_draw(game);
	}
}
