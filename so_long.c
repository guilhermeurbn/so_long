/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:02:46 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/23 17:09:04 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>


int close_window(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars -> mlx, vars ->win);
		return (0);
	}
	return (0);
}
int resize_window(int largura, int altura, t_vars *vars)
{
	printf("a janela foi redimensionada para: %dx%d\n", altura, largura);
	return (0);
}

int close_button(int x, int y, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
int key_press(int keycode, t_vars *vars)
{
	if (keycode != 65307)
		vars ->keypress_time = time(NULL);
	return (0);
}

int check_key_press(t_vars *vars)
{
	time_t current_time = time(NULL);
	if (current_time - vars ->keypress_time > 3)
	{
		printf("a tecla foi pressionado por mais de 3 segundos");
		vars->keypress_time = current_time;
	}
	return (0);
}
int mouse_enter(int x, int y, t_vars *vars)
{
	(void)x; (void)y;
	printf("Hello!\n");
	return (0);
}
int mouse_leave(int x, int y, t_vars *vars)
{
	(void)x; (void)y;
	printf("Bye!\n");
	return (0);
}


int main()
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "hello world!");
	vars.keypress_time = 0;

	mlx_hook(vars.win, 2, 1L << 0, close_window, &vars);  // Tecla pressionada
	mlx_hook(vars.win, 17, 1L << 17, close_button, &vars);  // Botão de fechar
	mlx_hook(vars.win, 26, 1L << 6, resize_window, &vars);  // Redimensionar
	mlx_hook(vars.win, 6, 1L << 0, mouse_enter, &vars);  // Mouse entra
	mlx_hook(vars.win, 7, 1L << 0, mouse_leave, &vars);  // Mouse sai
	mlx_loop_hook(vars.mlx, check_key_press, &vars);  // Checar o tempo da tecla pressionada
	mlx_loop(vars.mlx);
}
