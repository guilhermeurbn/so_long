/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:02:46 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/12 15:19:25 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    void *mlx;
    void *mlx_win;
    
    mlx = mlx_init();
    mlx = mlx_new_window(mlx, 1920, 1080, "hello World!");
    mlx_loop(mlx);
}