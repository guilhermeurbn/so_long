/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:53:51 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/31 13:54:08 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

t_data *game(void)
{
    static t_data x;
    return (&x);
}

int leave_window(int keycode)
{
    t_data *data = game();
    if (keycode == 65307)
    {
        if (data->mlx_ptr && data->win_ptr)
        {
            mlx_destroy_image(data->mlx_ptr, data->texture_img);
            mlx_destroy_image(data->mlx_ptr, data->cursor_img);
            mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        }
        exit(0);
    }
    return (0);
}

int render_next_frame(void)
{
    t_data *data = game();
    
    int x, y;

    if (!data->mlx_ptr || !data->win_ptr)
        return (1);

    mlx_clear_window(data->mlx_ptr, data->win_ptr);

    y = 0;
    while (y < 600)
    {
        x = 0;
        while (x < 800)
        {
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture_img, x, y);
            x += data->tex_width;
        }
        y += data->tex_height;
    }

    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->cursor_img, data->cursor_x, data->cursor_y);
    return (0);
}

int keypressed(int keycode)
{
    t_data *data = game();
    int step = 40;

    if (!data->mlx_ptr || !data->win_ptr)
        return (1);

    if (keycode == 'w' && data->cursor_y - step >= 0)
        data->cursor_y -= step;
    if (keycode == 's' && data->cursor_y + step <= 600 - data->img_height)
        data->cursor_y += step;
    if (keycode == 'a' && data->cursor_x - step >= 0)
        data->cursor_x -= step;
    if (keycode == 'd' && data->cursor_x + step <= 800 - data->img_width)
        data->cursor_x += step;
    if (keycode == 65307)
        leave_window(keycode);

    return (0);
}

int loop_hook(void)
{
    return render_next_frame();
}

int main(void)
{
    t_data *data = game();

    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
    {
        printf("Erro ao inicializar MiniLibX\n");
        return (1);
    }

    data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 600, "arco iris ");
    if (!data->win_ptr)
    {
        printf("Erro ao criar janela\n");
        return (1);
    }

    data->img_height = 800;
    data->img_width = 600;
    data->cursor_img = mlx_xpm_file_to_image(data->mlx_ptr, "cursor.xpm", &data->img_width, &data->img_height);
    if (!data->cursor_img)
    {
        printf("Erro ao carregar cursor.xpm\n");
        return (1);
    }

    data->tex_height = 800;
    data->tex_width = 600;
    data->texture_img = mlx_xpm_file_to_image(data->mlx_ptr, "texture.xpm", &data->tex_width, &data->tex_height);
    if (!data->texture_img)
    {
        printf("Erro ao carregar texture.xpm\n");
        return (1);
    }

    data->cursor_x = 400;
    data->cursor_y = 300;

    mlx_loop_hook(data->mlx_ptr, loop_hook, NULL);
    mlx_hook(data->win_ptr, 2, 1L << 0, keypressed, NULL);
    mlx_loop(data->mlx_ptr);
    
    return (0);
}