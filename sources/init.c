/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:24:33 by guisanto          #+#    #+#             */
/*   Updated: 2025/04/16 01:31:28 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int  img_init(t_game *game)
{
    game->img_backg = mlx_xpm_file_to_image
        (game->mlx, "images/wall.xpm", &game->img_w, &game->img_h);
    game->img_player = mlx_xpm_file_to_image
        (game->mlx, "images/iron_man.xpm", &game->img_w, &game->img_h);
    game->img_wall = mlx_xpm_file_to_image
        (game->mlx, "images/wall.xpm", &game->img_w, &game->img_h);
    game->img_colect = mlx_xpm_file_to_image
        (game->mlx, "images/colect.xpm", &game->img_w, &game->img_h);
}

static void size_window_init(t_game *game)
{
    int i;
    game->map_w = map[0] * 32;
    i = 0;
    while(game.map[i] != '\0')
        i++;
    game->map_h = i * 32;
}

void    game_init(t_game *game)
{
    game->mlx = mlx_init();
    size_window_init(game);
    game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "so_long");
    game->moves = 0;
    game->endgame = 0;
    img_init(game);
    map_draw(game);
}
