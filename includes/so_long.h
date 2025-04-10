/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:58:20 by guisanto          #+#    #+#             */
/*   Updated: 2025/04/10 12:21:34 by guisanto         ###   ########.fr       */
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
	void *mlx;
	void *win;
	char **map;
	void *img_backg;
	void *img_collect;
	void *img_exit
	int	map_w;
	int map_h;
	int n_colect;
	int n_player;
	int n_exit;
	int x_player;
	int y_player;
	int moves;
	int endgame;

} t_game;

void	img_draw(t_game *game, void *image, int x, int y);
int		map_draw(t_game *game);
void	game_init(t_game *game);
char	**read_map(char *path);
int		map_checker(t_game *game);
void	gameplay(t_game *game);
void	player_w(t_game *game);
void	player_d(t_game *game);
void	player_s(t_game *game);
void	player_a(t_game *game);
int		exit_game(t_game *game);
void	free_map(char **map);

#endif
