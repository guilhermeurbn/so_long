/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:22:33 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/30 22:22:34 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int leave_window(int keycode, t_data *data)
{
    if (keycode == 65307)
    {
        mlx_destroy_image(data->mlx_ptr, data->texture_img);
        mlx_destroy_image(data->mlx_ptr, data->cursor_img);
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);
    }
    return (0);
}

int render_next_frame(t_data *data)
{
    static int first_frame = 1;
    
    // Desenha o fundo apenas uma vez
    if (first_frame) 
    {
        int x = 0;
        int y = 0;
		
        // Desenha a textura no fundo
        while (y < 600)
        {
            x = 0;
            while (x < 800)
            {
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture_img, x, y);
                x += data->tex_width; // Repetir a textura no eixo X
            }
            y += data->tex_height; // Repetir a textura no eixo Y
        }
        first_frame = 0; // Garantir que a textura seja desenhada apenas uma vez
    }

    // Apenas desenha o cursor na nova posição
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
        leave_window(keycode, data);
    return (0);
}

int main(void)
{
    t_data data;

    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "arco iris ");
    data.img_height = 800;
    data.img_width = 600;
    data.cursor_img = mlx_xpm_file_to_image(data.mlx_ptr, "cursor.xpm", &data.img_width, &data.img_height);
    if (!data.cursor_img)
    {
        printf("error ao carregar o cursor.xpm\n");
        return (1);
    }
    data.tex_height = 800;
    data.tex_width = 600;
    data.texture_img = mlx_xpm_file_to_image(data.mlx_ptr, "texture.xpm", &data.tex_width, &data.tex_height);
    if (!data.texture_img)
    {
        printf("error ao carregar a texture.xpm\n");
        return (1);
    }
    data.cursor_x = 400;
    data.cursor_y = 300;
    
    mlx_loop_hook(data.mlx_ptr, render_next_frame, &data);
    mlx_hook(data.win_ptr, 2, 1L<<0, keypressed, &data);
    mlx_loop(data.mlx_ptr);
    return (0);    
}