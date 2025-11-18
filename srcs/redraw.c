/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:44:46 by chajeon           #+#    #+#             */
/*   Updated: 2024/05/27 13:10:23 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	renew_img_hss_a(t_map *map, int hss, int vss)
{
	char	*count;

	count = ft_itoa(map->count);
	if (!count)
		ft_print_error("malloc error", map, 1);
	draw_img(map->f_co, 0, 0, map);
	draw_img(map->f_h, 32, 0, map);
	mlx_put_string(map->mlx, count, 12, 15);
	draw_img(map->ma, hss, vss, map);
	draw_img(map->gr, hss + 32, vss, map);
	ft_printf("count: %d\n", map->count);
	free(count);
}

void	renew_img_hss_d(t_map *map, int hss, int vss)
{
	char	*count;

	count = ft_itoa(map->count);
	if (!count)
		ft_print_error("malloc error", map, 1);
	draw_img(map->f_co, 0, 0, map);
	draw_img(map->f_h, 32, 0, map);
	mlx_put_string(map->mlx, count, 12, 15);
	draw_img(map->md, hss, vss, map);
	draw_img(map->gr, hss - 32, vss, map);
	ft_printf("count: %d\n", map->count);
	free(count);
}

void	renew_img_vss_w(t_map *map, int hss, int vss)
{
	char	*count;

	count = ft_itoa(map->count);
	if (!count)
		ft_print_error("malloc error", map, 1);
	draw_img(map->f_co, 0, 0, map);
	draw_img(map->f_h, 32, 0, map);
	mlx_put_string(map->mlx, count, 12, 15);
	draw_img(map->mw, hss, vss, map);
	draw_img(map->gr, hss, vss + 32, map);
	ft_printf("count: %d\n", map->count);
	free(count);
}

void	renew_img_vss_s(t_map *map, int hss, int vss)
{
	char	*count;

	count = ft_itoa(map->count);
	if (!count)
		ft_print_error("malloc error", map, 1);
	draw_img(map->f_co, 0, 0, map);
	draw_img(map->f_h, 32, 0, map);
	mlx_put_string(map->mlx, count, 12, 15);
	draw_img(map->ms, hss, vss, map);
	draw_img(map->gr, hss, vss - 32, map);
	ft_printf("count: %d\n", map->count);
	free(count);
}
