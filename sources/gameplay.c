/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:23:16 by guisanto          #+#    #+#             */
/*   Updated: 2025/04/11 19:28:23 by guisanto         ###   ########.fr       */
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
int gameplay(t_game *game)
{
    
}