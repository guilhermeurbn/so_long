/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:24:33 by guisanto          #+#    #+#             */
/*   Updated: 2025/09/17 17:27:04 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	img_init(t_game *game)
{
	game->img_backg = mlx_xpm_file_to_image(game->mlx, "images/background.xpm",
			&game->img_w, &game->img_h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "images/iron_man2.xpm",
			&game->img_w, &game->img_h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm",
			&game->img_w, &game->img_h);
	game->img_colect = mlx_xpm_file_to_image(game->mlx, "images/colect.xpm",
			&game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "images/exit_close.xpm",
			&game->img_w, &game->img_h);
	//proteger imagens
}

static void	size_window_init(t_game *game)
{
	int	i;

	game->map_w = ft_strlen(game->map[0]) * 32;
	i = 0;
	while (game->map[i])
		i++;
	game->map_h = i * 32;
}

void	game_init(t_game *game)
{
	//proteger caso seu NULL
	game->mlx = mlx_init();
	size_window_init(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "so_long");
	game->moves = 0;
	game->endgame = 0;
	img_init(game);
	map_draw(game);
}
