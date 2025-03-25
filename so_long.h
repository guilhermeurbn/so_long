/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:58:20 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/25 16:09:23 by guisanto         ###   ########.fr       */
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
#include "so_long.xpm"

#ifdef __linux__
#include <X11/keysym.h>
# endif

typedef struct s_vars
{
    void    *img;
    void    *mlx_ptr;
    void    *win_ptr;
    int     x;
    int     y;
    int     color_index;
} t_data;

#endif
