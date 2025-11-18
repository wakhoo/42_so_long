/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:57:17 by chajeon           #+#    #+#             */
/*   Updated: 2024/04/20 11:32:33 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_img(mlx_image_t *img, int hss, int vss, t_map *map)
{
	if (mlx_image_to_window(map->mlx, img, hss, vss) < 0)
		ft_print_error("MLX Img print error", map, 1);
}

static void	draw_map2(t_map *map, int vs, int hs)
{
	int		hss;
	int		vss;

	hss = hs * 32;
	vss = vs * 32;
	if (map->map[vs][hs] == '1' && (hs == 0 || hs == (map->xlen - 1))
		&& (vs == 0 || vs == (map->ylen - 1)))
		draw_img(map->f_co, hss, vss, map);
	else if (map->map[vs][hs] == '1' && (vs == 0 || vs == (map->ylen - 1)))
		draw_img(map->f_h, hss, vss, map);
	else if (map->map[vs][hs] == '1')
		draw_img(map->f_v, hss, vss, map);
	else if (map->map[vs][hs] == '0' || map->map[vs][hs] == 'E')
		draw_img(map->gr, hss, vss, map);
	else if (map->map[vs][hs] == 'C')
		draw_img(map->fr, hss, vss, map);
	else if (map->map[vs][hs] == 'P')
		draw_img(map->ms, hss, vss, map);
	else if (map->map[vs][hs] == 'M')
		draw_img(map->mons, hss, vss, map);
}

void	draw_map(t_map *map)
{
	int	vs;
	int	hs;

	vs = 0;
	while (vs < map->ylen)
	{
		hs = 0;
		while (hs < map->xlen)
		{
			draw_map2(map, vs, hs);
			hs++;
		}
		vs++;
	}
}
