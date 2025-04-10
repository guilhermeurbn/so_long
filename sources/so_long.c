/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:07:58 by guisanto          #+#    #+#             */
/*   Updated: 2025/04/09 13:59:08 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;


    if (argc == 2)
    {
        game.map = read_map(argv[1]);
        if (map_checker(&game) && argv_checker(argv[1]))
        {
            game_init(&game);
            gameplay(&game);
            mlx_loop(game.mlx);
        }
    }
    else
    {
        if (game.map)
            free_map(game.map);
        printf("Error\n");
        exit(1);
    }
    return (0);
}
