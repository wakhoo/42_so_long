/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:58:21 by chajeon           #+#    #+#             */
/*   Updated: 2024/05/15 14:34:13 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#include <stdio.h>

void	ft_key_set(t_map *map)
{
	map->ccount = 0;
	map->ecount = 0;
	map->mcount = 0;
	map->pcount = 0;
	map->fccount = 0;
	map->fecount = 0;
	map->fmcount = 0;
	map->fpcount = 0;
	map->get_col = 0;
	map->count = 0;
	map->out = 0;
	return ;
}

void	floodfill(int x, int y, char passed, t_map *map)
{
	if (!map->mapf || !map->map)
		return ;
	if (x >= 0 && x <= map->xlen - 1 && y >= 0 && y <= map->ylen - 1
		&& map->mapf[y][x] != '1'
		&& map->mapf[y][x] != '2'
		&& map->mapf[y][x] != 'M')
	{
		if (map->mapf[y][x] == 'E')
			map->fecount++;
		else if (map->mapf[y][x] == 'C')
			map->fccount++;
		map->mapf[y][x] = passed;
		if (((x + 1) >= 0) && ((x + 1) < (map->xlen - 1)))
			floodfill(x + 1, y, passed, map);
		if (((x - 1) >= 0) && ((x - 1) <= (map->xlen - 1)))
			floodfill(x - 1, y, passed, map);
		if (((y + 1) >= 0) && ((y + 1) < (map->ylen - 1)))
			floodfill(x, y + 1, passed, map);
		if (((y - 1) >= 0) && ((y - 1) <= (map->ylen - 1)))
			floodfill(x, y - 1, passed, map);
	}
	return ;
}
