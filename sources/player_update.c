/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:51:06 by igvaz-fe          #+#    #+#             */
/*   Updated: 2025/09/22 12:45:33 by guisanto         ###   ########.fr       */
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

void	player_move(t_game *game, char key)
{
	player_update_image(key, game);
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
	}
	else if (game->map[game->y_player][game->x_player] == '1')
	{
		if (key == 'w')
			game->y_player += 1;
		else if (key == 's')
			game->y_player -= 1;
		else if (key == 'd')
			game->x_player -= 1;
		else if (key == 'a')
			game->x_player += 1;
	}
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		if (game->map[game->y_player][game->x_player] != 'E')
			game->map[game->y_player][game->x_player] = 'P';
		if (key == 'w' && game->map[game->y_player + 1][game->x_player] != 'E')
			game->map[game->y_player + 1][game->x_player] = '0';
		else if (key == 's' && game->map[game->y_player - 1][game->x_player] != 'E')
			game->map[game->y_player - 1][game->x_player] = '0';
		else if (key == 'd' && game->map[game->y_player][game->x_player - 1] != 'E')
			game->map[game->y_player][game->x_player - 1] = '0';
		else if (key == 'a' && game->map[game->y_player][game->x_player + 1] != 'E')
			game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		map_draw(game);
	}
}
