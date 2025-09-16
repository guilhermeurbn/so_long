/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:58:20 by guisanto          #+#    #+#             */
/*   Updated: 2025/09/16 11:20:41 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/libft.h"
# include "../libraries/mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifdef __linux__
#  include <X11/keysym.h>
# endif

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_colect;
	void	*img_exit;
	int		img_w;
	int		img_h;
	int		map_w;
	int		map_h;
	int		n_colect;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int		moves;
	int		endgame;

}			t_game;

# define KEY_W 119
# define KEY_S 115
# define KEY_D 100
# define KEY_A 97
# define KEY_ESC 65307
# define KEY_Q 113
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_RIGHT 65363
# define ARROW_LEFT 65361

void		img_draw(t_game *game, void *image, int x, int y);
int			map_draw(t_game *game);
void		game_init(t_game *game);
char		**read_map(char *path);
int			map_checker(t_game *game);
void		gameplay(t_game *game);
void		player_w(t_game *game);
void		player_d(t_game *game);
void		player_s(t_game *game);
void		player_a(t_game *game);
int			exit_game(t_game *game);
void		free_map(char **map);
char		**flood_fill(char **map, int start_x, int start_y);
char		**map_dup(char **map);
int			checker_e_c(t_game *game);
void		free_dup(char **dup, int i);
int			find_player(char **map, int *x, int *y);

#endif
