/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:58:20 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/30 17:48:27 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mlx/mlx.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

#ifdef __linux__
#include <X11/keysym.h>
# endif

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img;
    void    *cursor_img; // Adicionando a imagem do cursor
    int     img_width;
    int     img_height;
    int     cursor_x;
    int     cursor_y;
    int     move_count;
    int     color_index;
}   t_data;

#endif
