/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:23:13 by guisanto          #+#    #+#             */
/*   Updated: 2025/09/16 10:45:06 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_dup(char **dup, int i)
{
    int j = 0;
    while (j < i)
    {
        free(dup[j]);
        j++;
    }
    free(dup);
}

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
            free_dup(dup, i);
            return NULL;
        }
        i++;
    }
    dup[i] = NULL;
    return dup;
}

int find_player(char **map, int *x, int *y)
{
    int i = 0;
    int j;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
            {
                *x = j;
                *y = i;
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}

int checker_E_C(t_game *game)
{
    int i;
    int j;
    i = 0;

    char **map_dupp = map_dup(game->map);
    if (!map_dupp)
        return 0;
    if (!find_player(map_dupp, &game->x_player, &game->y_player))
        return (free_map(map_dupp), 0);
    flood_fill(map_dupp, game->x_player, game->y_player);
    while (map_dupp[i])
    {
        j = 0;
        while (map_dupp[i][j])
        {
            if (map_dupp[i][j] == 'E' || map_dupp[i][j] == 'C')
                return (free_map(map_dupp), 0);
            j++;
        }
        i++;
    }
    free_map(map_dupp);
    return 1;
}
