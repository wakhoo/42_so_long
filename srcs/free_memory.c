/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:33:51 by chajeon           #+#    #+#             */
/*   Updated: 2024/06/13 11:58:03 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_free_imgs(t_map *map)
{
	if (map->gr)
		mlx_delete_image(map->mlx, map->gr);
	if (map->ma)
		mlx_delete_image(map->mlx, map->ma);
	if (map->md)
		mlx_delete_image(map->mlx, map->md);
	if (map->mw)
		mlx_delete_image(map->mlx, map->mw);
	if (map->ms)
		mlx_delete_image(map->mlx, map->ms);
	if (map->mons)
		mlx_delete_image(map->mlx, map->mons);
	if (map->f_v)
		mlx_delete_image(map->mlx, map->f_v);
	if (map->f_h)
		mlx_delete_image(map->mlx, map->f_h);
	if (map->f_co)
		mlx_delete_image(map->mlx, map->f_co);
	if (map->fr)
		mlx_delete_image(map->mlx, map->fr);
	if (map->p)
		mlx_delete_image(map->mlx, map->p);
	return ;
}

void	ft_tout_free(t_map *map, int check)
{
	if (map->map != NULL)
	{
		ft_free_arr(map->map);
		map->map = NULL;
	}
	if (map->mapf != NULL)
	{
		ft_free_arr(map->mapf);
		map->mapf = NULL;
	}
	if (check == 1)
	{
		ft_free_imgs(map);
		map = NULL;
	}
	return ;
}
