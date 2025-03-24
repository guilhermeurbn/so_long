/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:02:46 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/24 16:59:55 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int close_window(int keycode, t_vars *vars)
{
	if (keycode == 12) // 12 is the keycode for Q on macOS
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int main()
{
	t_vars vars;
	
	vars.mlx = mlx_init();

	vars.win = mlx_new_window(vars.mlx, 800, 600, "So_long\n");
	mlx_hook(vars.win, 2, 1L<<0, close_window, &vars); // Hook for key press
	mlx_loop(vars.mlx);
}
