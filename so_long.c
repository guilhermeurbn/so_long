/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:02:46 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/26 22:49:11 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int leave_window(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
}

void draw_circle(t_data *data, int radius)
{
	int x;
	int y;

	y = -radius;
	while(y <= radius)
	{
		x = -radius;
		while(x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, data->y, data->color_index);
			x++;
		}
		y++;
	}
}
int render_next_frame(t_data *data)
{	
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_circle(data, 20);
	return (0);
}
int keypressed(int keycode, t_data *data)
{
    int raio = 10;
    
    if (keycode == 'w' && data->y - 10 >= raio)
    {
        data->y -= 10;
        data->move_count++;
        printf("Movimentos: %d\n", data->move_count);
    }    
    if (keycode == 's' && data->y + 10 <= 600 - raio)
    {
        data->y += 10;
        data->move_count++;
        printf("Movimentos: %d\n", data->move_count);
    }    
    if (keycode == 'a' && data->x - 10 >= raio)
    {
        data->x -= 10;
        data->move_count++;
        printf("Movimentos: %d\n", data->move_count);
    }    
    if (keycode == 'd' && data->x + 10 <= 800 - raio)
    {
        data->x += 10;
        data->move_count++;
        printf("Movimentos: %d\n", data->move_count);
    }    
    if (keycode == 65307) // Tecla ESC para fechar
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);
    }
    return (0);
}

int main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "arco iris ");
	data.x = 400;
	data.y = 300;
	data.color_index = 0xFF0000;
	
	mlx_loop_hook(data.mlx_ptr, render_next_frame, &data);
	mlx_hook(data.win_ptr, 2, 1L<<0, keypressed, &data);
	mlx_loop(data.mlx_ptr);
	return (0);	
}
