/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:54:02 by chajeon           #+#    #+#             */
/*   Updated: 2024/04/20 12:36:12 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static mlx_image_t	*load_xpm(char *str, mlx_t *mlx, t_map *map)
{
	xpm_t		*xpm;
	mlx_image_t	*img;

	xpm = mlx_load_xpm42(str);
	if (!xpm)
	{
		puts(mlx_strerror(mlx_errno));
		ft_print_error("XPM error", map, 1);
	}
	img = mlx_texture_to_image(mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	if (!img)
	{
		puts(mlx_strerror(mlx_errno));
		ft_print_error("Img error", map, 1);
	}
	return (img);
}

void	ft_set_images(t_map *map)
{
	map->gr = load_xpm("./img/ground.xpm42", map->mlx, map);
	map->ma = load_xpm("./img/marche_a.xpm42", map->mlx, map);
	map->md = load_xpm("./img/marche02_f.xpm42", map->mlx, map);
	map->mw = load_xpm("./img/marche_w.xpm42", map->mlx, map);
	map->ms = load_xpm("./img/marche_s.xpm42", map->mlx, map);
	map->mons = load_xpm("./img/monster.xpm42", map->mlx, map);
	map->f_v = load_xpm("./img/fance_vir.xpm42", map->mlx, map);
	map->f_h = load_xpm("./img/fance_hor.xpm42", map->mlx, map);
	map->f_co = load_xpm("./img/fance_co.xpm42", map->mlx, map);
	map->fr = load_xpm("./img/fraise.xpm42", map->mlx, map);
	map->p = load_xpm("./img/porte_sun.xpm42", map->mlx, map);
	if (!map->gr || !map->ma || !map->md || !map->mw || !map->ms
		|| !map->mons || !map->f_v || !map->f_h || !map->f_co
		|| !map->fr || !map->p)
		ft_print_error("MLX Img malloc error", map, 1);
}
