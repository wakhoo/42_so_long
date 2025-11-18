/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:44:52 by chajeon           #+#    #+#             */
/*   Updated: 2024/04/19 17:59:37 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move_w(t_map *map)
{
	map->ystart--;
	map->xss = map->xstart * 32;
	map->yss = map->ystart * 32;
	map->check = map->map[map->ystart][map->xstart];
	if (map->check == '0' || map->check == 'C' || map->check == 'P'
		|| (map->get_col != map->ccount && map->check == 'E'))
	{
		map->count++;
		renew_img_vss_w(map, map->xss, map->yss);
		if (map->map[map->ystart][map->xstart] == 'C')
		{
			map->get_col++;
			map->map[map->ystart][map->xstart] = '0';
		}
		if (map->ccount == map->get_col)
			map->out = 1;
	}
	else if (map->map[map->ystart][map->xstart] == 'M')
		hello_monster(map, map->mlx);
	else if (map->get_col == map->ccount && map->check == 'E')
		end_game(map, map->mlx);
	else
		map->ystart++;
	return ;
}

void	ft_move_s(t_map *map)
{
	map->ystart++;
	map->xss = map->xstart * 32;
	map->yss = map->ystart * 32;
	map->check = map->map[map->ystart][map->xstart];
	if (map->check == '0' || map->check == 'C' || map->check == 'P'
		|| (map->get_col != map->ccount && map->check == 'E'))
	{
		map->count++;
		renew_img_vss_s(map, map->xss, map->yss);
		if (map->map[map->ystart][map->xstart] == 'C')
		{
			map->get_col++;
			map->map[map->ystart][map->xstart] = '0';
		}
		if (map->ccount == map->get_col)
			map->out = 1;
	}
	else if (map->map[map->ystart][map->xstart] == 'M')
		hello_monster(map, map->mlx);
	else if (map->get_col == map->ccount && map->check == 'E')
		end_game(map, map->mlx);
	else
		map->ystart--;
	return ;
}

void	ft_move_a(t_map *map)
{
	map->xstart--;
	map->xss = map->xstart * 32;
	map->yss = map->ystart * 32;
	map->check = map->map[map->ystart][map->xstart];
	if (map->check == '0' || map->check == 'C' || map->check == 'P'
		|| (map->get_col != map->ccount && map->check == 'E'))
	{
		map->count++;
		renew_img_hss_a(map, map->xss, map->yss);
		if (map->map[map->ystart][map->xstart] == 'C')
		{
			map->get_col++;
			map->map[map->ystart][map->xstart] = '0';
		}
		if (map->ccount == map->get_col)
			map->out = 1;
	}
	else if (map->map[map->ystart][map->xstart] == 'M')
		hello_monster(map, map->mlx);
	else if (map->get_col == map->ccount && map->check == 'E')
		end_game(map, map->mlx);
	else
		map->xstart++;
	return ;
}

void	ft_move_d(t_map *map)
{
	map->xstart++;
	map->xss = map->xstart * 32;
	map->yss = map->ystart * 32;
	map->check = map->map[map->ystart][map->xstart];
	if (map->check == '0' || map->check == 'C' || map->check == 'P'
		|| (map->get_col != map->ccount && map->check == 'E'))
	{
		map->count++;
		renew_img_hss_d(map, map->xss, map->yss);
		if (map->map[map->ystart][map->xstart] == 'C')
		{
			map->get_col++;
			map->map[map->ystart][map->xstart] = '0';
		}
		if (map->ccount == map->get_col)
			map->out = 1;
	}
	else if (map->map[map->ystart][map->xstart] == 'M')
		hello_monster(map, map->mlx);
	else if (map->get_col == map->ccount
		&& map->map[map->ystart][map->xstart] == 'E')
		end_game(map, map->mlx);
	else
		map->xstart--;
	return ;
}
