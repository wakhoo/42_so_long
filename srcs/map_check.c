/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:57:23 by chajeon           #+#    #+#             */
/*   Updated: 2024/05/15 14:05:03 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_map_size(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
		i++;
	j = i - 1;
	while (j > 0)
	{
		if (ft_strlen(map->map[j]) != ft_strlen(map->map[j - 1]))
			ft_print_error("Map shape error!", map, 0);
		j--;
	}
	if (i * ft_strlen(map->map[i - 1]) > 2000)
		ft_print_error("Map is TOO BIG!", map, 0);
	map->ylen = i;
	map->xlen = ft_strlen(map->map[i - 1]);
	return ;
}

static void	ft_check_count(int i, int k, t_map *map)
{
	if (map->map[i][k] == 'P')
	{
		map->xstart = k;
		map->ystart = i;
		map->pcount++;
	}
	if (map->map[i][k] == 'M')
		map->mcount++;
	if (map->map[i][k] == 'C')
		map->ccount++;
	if (map->map[i][k] == 'E')
	{
		map->xporte = k;
		map->yporte = i;
		map->ecount++;
	}
}

static void	ft_map_char(int i, int k, t_map *map)
{
	char	*valied;

	valied = "10EPCM";
	while (map->map[i])
	{
		k = 0;
		while (map->map[i][k])
		{
			if (ft_strchr(valied, map->map[i][k]) == NULL)
				ft_print_error("Invalied char XD", map, 0);
			ft_check_count(i, k, map);
			k++;
		}
		i++;
	}
	return ;
}

static void	ft_cloture(t_map *map)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = map->ylen;
	len = map->xlen;
	while (map->map[0][i])
	{
		if (map->map[0][i] != '1' || map->map[count - 1][i] != '1')
			ft_print_error("Il y a un trou dans la clôture XD", map, 0);
		i++;
	}
	i = 0;
	while (i < count)
	{
		if (map->map[i][0] != '1' || map->map[i][len - 1] != '1')
			ft_print_error("Il y a un trou dans la clôture XD", map, 0);
		i++;
	}
	return ;
}

void	ft_map_checker(t_map *map)
{
	if (!map->mapf || !map->map)
		ft_print_error("nono", map, 0);
	ft_key_set(map);
	ft_map_size(map);
	ft_map_char(0, 0, map);
	ft_cloture(map);
	if (map->ecount != 1 || map->pcount != 1 || map->ccount < 1)
		ft_print_error("Lack of essential elements", map, 0);
	floodfill(map->xstart, map->ystart, '2', map);
	if (map->ecount != map->fecount || map->ccount != map->fccount)
		ft_print_error("I can't reach to end!", map, 0);
	return ;
}
