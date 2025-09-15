/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:50:56 by igvaz-fe          #+#    #+#             */
/*   Updated: 2025/09/15 15:48:31 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char **flood_fill(char **map, int x, int y)
{
    if (y < 0 || !map[y] || x < 0 || x >= (int)ft_strlen(map[y]))
        return 0;


    if (map[y][x] == '1' || map[y][x] == 'V')
        return 0;
    map[y][x] = 'V';

    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);

    return map;
}

// Duplicar matriz de chars (char **map), retornando nova matriz alocada
char **map_dup(char **map)
{
    int i = 0;
    int len = 0;
    char **dup;

    while (map[len])
        len++;
    dup = malloc(sizeof(char *) * (len + 1));
    if (!dup)
        return NULL;
    while (i < len)
    {
        dup[i] = ft_strdup(map[i]);
        if (!dup[i])
        {
            int j = 0;
            while (j < i)
            {
                free(dup[j]);
                j++;
            }
            free(dup);
            return NULL;
        }
        i++;
    }
    dup[i] = NULL;
    return dup;
}

int checker_E_C(t_game *game)
{
    int i = 0;
    int j = 0;
    char **map_dupp = map_dup(game->map);
    if (!map_dupp)
        return 0;

	// Inicializar as coordenadas do jogador
	i = 0;
	while (map_dupp[i])
	{
		j = 0;
		while (map_dupp[i][j])
		{
			if (map_dupp[i][j] == 'P')
			{
				game->x_player = j;
				game->y_player = i;
				break;
			}
			j++;
		}
		if (map_dupp[i][j] == 'P')
			break;
		i++;
	}

	printf("Starting flood_fill at x=%d, y=%d\n", game->x_player, game->y_player);
    printf("checker_E_C: starting flood_fill\n");
    flood_fill(map_dupp, game->x_player, game->y_player);
    printf("checker_E_C: flood_fill completed\n");

    while(map_dupp[i])
    {
        printf("checker_E_C: checking line %d: %s\n", i, map_dupp[i]);
        j = 0;
        while (map_dupp[i][j])
        {
            if (map_dupp[i][j] == 'E' || map_dupp[i][j] == 'C')
            {
                printf("checker_E_C: found unreachable '%c' at line %d, col %d\n", map_dupp[i][j], i, j);
                free_map(map_dupp);
                return 0;
            }
            j++;
        }
        i++;
    }
    free_map(map_dupp);
    return 1;
}


static int	is_retangular(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_wall(char **map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map[i])
		i++;
	while (map[0][j] && map[i - 1][j])
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	is_pec(t_game *game)
{
	int	i;
	int	j;

	game->n_colect = 0;
	game->n_player = 0;
	game->n_exit = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->n_player++;
			else if (game->map[i][j] == 'E')
				game->n_exit++;
			else if (game->map[i][j] == 'C')
				game->n_colect++;
			j++;
		}
		i++;
	}
	if (game->n_player != 1 || game->n_exit != 1 || game->n_colect == 0)
		return (0);
	return (1);
}

static int	is_validate(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_checker(t_game *game)
{
	printf("map_checker: starting checks: is_retangular, is_wall, is_pec, is_validate, checker_E_C\n");
	if (is_retangular(game->map) && is_wall(game->map) && is_pec(game)
		&& is_validate(game->map) && checker_E_C(game))
		return (1);
	return (0);
}