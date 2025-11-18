/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:58:25 by chajeon           #+#    #+#             */
/*   Updated: 2024/06/13 12:03:56 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	**ft_double_arr(int i, int k, char **map, char *tmp)
{
	char	**resmap;
	char	*tmp2;

	while (map && map[i])
		i++;
	resmap = (char **)malloc(sizeof(char **) * (i + 2));
	if (!resmap)
		return (ft_free_arr(resmap), ft_free_arr(map), free(tmp), NULL);
	while (k < i)
	{
		resmap[k] = map[k];
		k++;
	}
	if (ft_strrchr(tmp, '\n'))
	{
		tmp2 = ft_substr(tmp, 0, ft_strlen(tmp) - 1);
		free(tmp);
		tmp = tmp2;
	}
	resmap[k] = tmp;
	resmap[k + 1] = 0;
	free(map);
	return (resmap);
}

static char	**ft_it_broken(char **map, char *tmp)
{
	ft_free_arr(map);
	free(tmp);
	return (NULL);
}

static char	**ft_get_map(char *filename)
{
	int		map_fd;
	char	*tmp;
	char	**map;

	map_fd = open(filename, O_RDONLY);
	if (map_fd <= 0)
		return (NULL);
	tmp = get_next_line(map_fd, GNL);
	map = NULL;
	while (tmp != NULL)
	{
		if (tmp == NULL || tmp[0] == '\n' || tmp[0] == '\0')
			return (close(map_fd), ft_it_broken(map, tmp));
		map = ft_double_arr(0, 0, map, tmp);
		if (!map)
			return (close(map_fd), ft_it_broken(map, tmp));
		tmp = get_next_line(map_fd, GNL);
	}
	close(map_fd);
	return (map);
}

void	ft_get_maps(char *filename, t_map *map)
{
	map->map = NULL;
	map->mapf = NULL;
	map->map = ft_get_map(filename);
	if (map->map == NULL)
		ft_print_error("Can not read the map XD", map, 0);
	map->mapf = ft_get_map(filename);
	if (map->mapf == NULL)
		ft_print_error("Can not read the map XD", map, 0);
	return ;
}
