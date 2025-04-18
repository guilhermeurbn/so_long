/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:23:16 by guisanto          #+#    #+#             */
/*   Updated: 2025/04/17 18:53:51 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void game_events(int keycode, t_game *game)
{
    if (keycode == 119)
    {
        game->y_player -= 1;
        player_w(game);
    }
    else if (keycode == 115)
    {
        game->y_player += 1;
        player_s(game);
    }
    else if (keycode == 100)
    {
        game->x_player += 1;
        player_d(game);
    }
    else if (keycode == 97)
    {
        game->x_player -= 1;
        player_a(game);
    }
}
static int keypress(int keycode, t_game *game)
{
    if (keycode == 65307 || keycode == 113)
        exit_game(game);
    else if(!game->endgame)
    {
        game_events(keycode, game);
        printf("Moves:%d\n", game->moves);
    }
    return (0);
}
void gameplay(t_game *game)
{
    mlx_hook(game->win, 2, 1L<<0, keypress, game);
    mlx_hook(game->win, 17, 1L<<17, exit_game, game);
    mlx_hook(game->win, 9, 1L<<21, map_draw, game);
}
