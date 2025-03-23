/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:58:20 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/23 12:44:15 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* Incluindo bibliotecas padrão */
#include <stdlib.h>
#include <stdio.h>

/* Inclusão da biblioteca MLX */
#ifdef __APPLE__
    #include <mlx.h>  // Para macOS
#else
    #include "minilibx-linux/mlx.h"  // Para Linux
#endif

/* Outras dependências */
#include <X11/X.h>
#include <X11/keysym.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"


#endif
