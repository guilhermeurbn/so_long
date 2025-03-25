/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:08:54 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/25 15:55:24 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* int mouse_move(int x, int y, t_vars *vars)
{
	printf("posicao atual do mouse: (%d, %d)\n", x, y);
	return (0);
}

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
int mouse_enter(int keycode, t_vars *vars)
{
	printf("hello mouse");
	return (0);
}
int mouse_leave(int keycode, t_vars *vars)
{
	printf("bye mouse");
	return (0);
}
int key_pressed(int keycode, t_vars *vars)
{
	if (keycode == 65307) 
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else 
		printf("keycode: %d\n", keycode);
	return (0);
}
int pressed_time(int keycode, t_vars *vars)
{
	printf("apertou a tecla '%d' por muito tempo", keycode);
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
	mlx_hook(vars.win, 3, 1L<<1, pressed_time, &vars);
	mlx_hook(vars.win, 7, 1<<4, mouse_enter, &vars);
	mlx_hook(vars.win, 8, 1<<5, mouse_leave, &vars);
	mlx_hook(vars.win, 6, 1L<<6, mouse_move, &vars);
	mlx_loop(vars.mlx);
} */