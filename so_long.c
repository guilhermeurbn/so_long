/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:02:46 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/25 14:51:28 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int expose(t_vars *vars)
{
	printf("hello\n");
	return (0);
}
int x_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int key_hook(int keycode, t_vars *vars)
{
	if (keycode == 113)
		printf("print Q");
	printf("hello from hook\n");
	return (0);
}

int mouse_click(int keycode, t_vars *vars)
{
	printf("mouse\n");
	return (0);
}
int key_pressed(int keycode, t_vars *vars)
{
	if (keycode == XK_q) 
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else 
		printf("keycode: %d\n", keycode);
	return (0);
}
int main()
{
	t_vars vars;
	
	vars.mlx = mlx_init();

	vars.win = mlx_new_window(vars.mlx, 800, 600, "So_long\n");
	mlx_hook(vars.win, 12, 1L<<15, expose, &vars);
	mlx_hook(vars.win, 17, 0, x_window, &vars);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_click, &vars);
	mlx_hook(vars.win, 2, 1L<<0, key_pressed, &vars);
	mlx_loop(vars.mlx);
}




























/* 

Codigo para descobrir qual e cada tecla!!


#include <stdio.h>
#include "so_long.h"

int key_press(int keycode, t_vars *vars)
{
    printf("Keycode: %d\n", keycode);
    if (keycode == 113) // Q no macOS (QWERTY US)
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
    vars.win = mlx_new_window(vars.mlx, 800, 600, "So_long");

    mlx_hook(vars.win, 2, 1L<<0, key_press, &vars);
    mlx_loop(vars.mlx);
} */
