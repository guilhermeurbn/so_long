/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:58:20 by guisanto          #+#    #+#             */
/*   Updated: 2025/04/01 16:18:27 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "mlx/mlx.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

#ifdef __linux__
#include <X11/keysym.h>
# endif

typedef struct s_game
{
    void    *mlx;
    void    *win;
    t_map   map;
    t_player    player;
    t_collectible   collectible;
    t_exit  exit;
    int   total_collectible;
}   t_game;



typedef struct s_player
{
    int     x;
    int     y;
    int     *img;
    int     move;
}   t_player;

typedef struct s_map
{
    int     x;
    int     y;
    int     *img;
}   t_map;

typedef struct s_collectible
{
    int     x;
    int     y;
    int     *img;
    int     collect;
}   t_collectible;

typedef struct s_exit
{
    int     x;
    int     y;
    int     *img;
    int     open;
    
}   t_exit;

#endif
