/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:51:06 by igvaz-fe          #+#    #+#             */
/*   Updated: 2025/09/16 14:54:05 by afpachec         ###   ########.fr       */
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

void	player_w(t_game *game)
{
	player_update_image('w', game);
	if (game->map[game->y_player][game->x_player] == 'E' && game->n_colect == 0)
	{
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		game->endgame = 1;
		exit_game(game);
		map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1')
		game->y_player += 1;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		if (game->map[game->y_player][game->x_player] != 'E')
			game->map[game->y_player][game->x_player] = 'P';
		if (game->map[game->y_player + 1][game->x_player] != 'E')
			game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	player_s(t_game *game)
{
	player_update_image('s', game);
	if (game->map[game->y_player][game->x_player] == 'E' && game->n_colect == 0)
	{
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		game->endgame = 1;
		exit_game(game);
		map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1')
		game->y_player -= 1;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		if (game->map[game->y_player][game->x_player] != 'E')
			game->map[game->y_player][game->x_player] = 'P';
		if (game->map[game->y_player - 1][game->x_player] != 'E')
			game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	player_d(t_game *game)
{
	player_update_image('d', game);
	if (game->map[game->y_player][game->x_player] == 'E' && game->n_colect == 0)
	{
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		game->endgame = 1;
		exit_game(game);
		map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1')
		game->x_player -= 1;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		if (game->map[game->y_player][game->x_player] != 'E')
			game->map[game->y_player][game->x_player] = 'P';
		if (game->map[game->y_player][game->x_player - 1] != 'E')
			game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	player_a(t_game *game)
{
	player_update_image('a', game);
	if (game->map[game->y_player][game->x_player] == 'E' && game->n_colect == 0)
	{
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		game->endgame = 1;
		exit_game(game);
		map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1')
		game->x_player += 1;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		if (game->map[game->y_player][game->x_player] != 'E')
			game->map[game->y_player][game->x_player] = 'P';
		if (game->map[game->y_player][game->x_player + 1] != 'E')
			game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		map_draw(game);
	}
}
