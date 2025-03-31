/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:58:20 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/31 13:35:32 by guisanto         ###   ########.fr       */
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
    void    *mlx_ptr;        // Ponteiro para a conexão com o servidor gráfico
    void    *win_ptr;        // Ponteiro para a janela
    void    *cursor_img;     // Ponteiro para a imagem do cursor
    void    *texture_img;    // Ponteiro para a imagem da textura
    int     cursor_x;        // Posição X do cursor
    int     cursor_y;        // Posição Y do cursor
    int     img_width;       // Largura da imagem do cursor
    int     img_height;      // Altura da imagem do cursor
    int     tex_width;       // Largura da textura
    int     tex_height;      // Altura da textura
    int     color_index;     // Cor do fundo ou outros elementos, se necessário
    int     move_count;
} t_data;

t_data *game(void);

#endif
