/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:23:16 by guisanto          #+#    #+#             */
/*   Updated: 2025/04/22 10:07:39 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void game_events(int keycode, t_game *game)
{
    if (keycode == KEY_W || keycode == ARROW_UP)
    {
        game->y_player -= 1;
        player_w(game);
    }
    else if (keycode == KEY_S || keycode == ARROW_DOWN)
    {
        game->y_player += 1;
        player_s(game);
    }
    else if (keycode == KEY_D || keycode == ARROW_RIGHT)
    {
        game->x_player += 1;
        player_d(game);
    }
    else if (keycode == KEY_A || keycode == ARROW_LEFT)
    {
        game->x_player -= 1;
        player_a(game);
    }
}

static int keypress(int keycode, t_game *game)
{
    if (keycode == KEY_ESC || keycode == KEY_Q)
        exit_game(game);
    else if(!game->endgame)
    {
        game_events(keycode, game);
        write(1, "\033[1;33mMoves: \033[0m", 19);
        ft_putnbr_fd(game->moves, 1);
        write(1, "\n", 1);
    }
    return (0);
}
void gameplay(t_game *game)
{
    mlx_hook(game->win, 2, 1L<<0, keypress, game);
    mlx_hook(game->win, 17, 1L<<17, exit_game, game);
    mlx_hook(game->win, 9, 1L<<21, map_draw, game);
}
