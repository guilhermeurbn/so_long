/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:07:58 by guisanto          #+#    #+#             */
/*   Updated: 2025/04/11 17:15:30 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int argv_checker(char *argv)
{
	int i;
	
	if (!argv)
		return (0)
	i = 0;
	while(argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && agrv[i - 1] == 'e' && argv[i - 2] == 'b' && argv[i - 3] == '.')
		return (1);
	return (0);
}

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
	return (0);
}
