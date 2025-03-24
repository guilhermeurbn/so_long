/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:58:20 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/24 17:35:28 by guisanto         ###   ########.fr       */
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


typedef struct s_vars
{
    void *mlx;
    void *win;
	int	holding_q;
} t_vars;

#endif
