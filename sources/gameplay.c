/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:23:16 by guisanto          #+#    #+#             */
/*   Updated: 2025/04/16 01:22:41 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void game_events(int keycode, t_game *game)
{   
    if (keycode == KEY_W || keycode == KEY_UP)
    {
        game->y_player -= 1;
        player_w(game);
    }
    else if (keycode == KEY_S || keycode == KEY_DOWN)
    {
        game->y_player += 1;
        player_s(game);
    }
    else if (keycode == KEY_D || keycode == KEY_RIGHT)
    {
        game->x_player += 1;
        player_d(game);
    }
    else if (keycode == KEY_A || keycode == KEY_LEFT)
    {
        game->x_player -= 1;
        player_a(game);
    }
}
static int keypress(int keycode, t_game *game)
{
    if(keypress == KEY_ESQ || keypress == KEY_Q)
        exit_game(game);
    else if(!game->endgame)
    {
        game_events(keycode, game);
        printf("Moves:%d", game->moves);
    }
    return (0);
}
int gameplay(t_game *game)
{
    mlx_hook(game->win, 2, 1L<<0, keypress, &game);
    mlx_hook(game->win, 17, 1L<<17, exit_game, &game);
    mlx_hook(game->win, 9, 1L<<21, map_draw, &game);
}