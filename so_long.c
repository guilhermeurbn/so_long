/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:02:46 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/30 18:12:11 by guisanto         ###   ########.fr       */
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
	return (0);
}
/* void draw_circle(t_data *data, int radius)
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
} */
int render_next_frame(t_data *data)
{	
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->cursor_img, data->cursor_x, data->cursor_y);
	return (0);
}
int keypressed(int keycode, t_data *data)
{
    int step = 40;

    if (keycode == 'w' && data->cursor_y - step >= 0)
        data->cursor_y -= step;
    if (keycode == 's' && data->cursor_y + step <= 600 - data->img_height)
        data->cursor_y += step;
    if (keycode == 'a' && data->cursor_x - step >= 0)
        data->cursor_x -= step;
    if (keycode == 'd' && data->cursor_x + step <= 800 - data->img_width)
        data->cursor_x += step;
    if (keycode == 65307) // ESC para sair
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
	data.color_index = 0xFF0000;
	data.img_height = 50;
	data.img_width = 50;
	data.cursor_img = mlx_xpm_file_to_image(data.mlx_ptr, "cursor.xpm", &data.img_width, &data.img_height);
	if (!data.cursor_img)
	{
		printf("error ao carrear o cursor.xpm\n");
		return (1);
	}
	data.cursor_x = 400;
	data.cursor_y = 300;
	
	mlx_loop_hook(data.mlx_ptr, render_next_frame, &data);
	mlx_hook(data.win_ptr, 2, 1L<<0, keypressed, &data);
	mlx_loop(data.mlx_ptr);
	return (0);	
}
