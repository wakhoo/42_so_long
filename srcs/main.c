/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:55:38 by chajeon           #+#    #+#             */
/*   Updated: 2024/06/13 11:58:43 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_same(t_map *map)
{
	int	j;
	int	i;

	i = 0;
	if (!map->mapf || !map->map)
		ft_print_error("fifi", map, 0);
	while (map->map[i] && map->mapf[i])
	{
		j = 0;
		while (map->map[i][j] && map->mapf[i][j])
		{
			if (!(map->map[i][j] == map->mapf[i][j]))
				ft_print_error("pas meme", map, 0);
			j++;
		}
		i++;
	}
	if (map->map[i] != map->mapf[i])
		ft_print_error("pas meme", map, 0);
	return ;
}

int32_t	main(int argc, char **argv)
{
	t_map	map;

	map.map = NULL;
	map.mapf = NULL;
	if (argc != 2)
		ft_print_error("Worng format XD\nTry ./so_long [map path]", &map, 0);
	if (ft_file_check(argv[1]) == 0)
		ft_print_sans("Worng extension map file should be .ber");
	ft_get_maps(argv[1], &map);
	check_same(&map);
	ft_map_checker(&map);
	ft_free_arr(map.mapf);
	map.mapf = NULL;
	map.mlx = mlx_init(32 * map.xlen, 32 * map.ylen, "SO LONG", true);
	if (!map.mlx)
		ft_print_error("mlx error", &map, 0);
	ft_set_images(&map);
	draw_map(&map);
	mlx_key_hook(map.mlx, &ft_my_keyhook, &map);
	mlx_loop(map.mlx);
	ft_tout_free(&map, 1);
	mlx_terminate(map.mlx);
	get_next_line(0, CLEAR);
	return (EXIT_SUCCESS);
}
