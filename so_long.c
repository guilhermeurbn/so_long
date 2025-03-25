/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:02:46 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/25 16:36:13 by guisanto         ###   ########.fr       */
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

int render_next_frame(t_data *data)
{

	static int frame_count = 0;
	static int color_switch = 15;
	
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->x, data->y, data->color_index, "42");
	data->x += 2.5;
	if (data->x > 800)
		data->x = 0;
		
	frame_count++;
	if (frame_count >= color_switch)
	{
		if (data->color_index == 0xFF0000)
			data->color_index = 0x00FF00;
		else if (data->color_index == 0x00FF00)
			data->color_index = 0x0000FF;
		else
			data->color_index = 0xFF0000;
		frame_count = 0;
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
	mlx_key_hook(data.win_ptr, leave_window, &data);
	mlx_loop(data.mlx_ptr);
	return (0);	
}
