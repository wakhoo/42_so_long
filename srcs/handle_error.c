/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:04:04 by chajeon           #+#    #+#             */
/*   Updated: 2024/06/13 12:01:15 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_print_error(char *message, t_map *map, int check)
{
	ft_printf("Error\n%s\n", message);
	get_next_line(0, CLEAR);
	if (map->map != NULL || map->mapf != NULL)
		ft_tout_free(map, check);
	exit(0);
}

void	ft_print_sans(char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(0);
}

void	ft_free_arr(char **tofree)
{
	int	i;

	i = 0;
	if (!tofree)
		return ;
	while (tofree[i])
	{
		free(tofree[i]);
		i++;
	}
	free(tofree);
}

void	hello_monster(t_map *map, mlx_t *mlx)
{
	ft_printf("GAME OVER\n");
	ft_tout_free(map, 1);
	mlx_terminate(mlx);
	get_next_line(0, CLEAR);
	exit(0);
}

void	end_game(t_map *map, mlx_t *mlx)
{
	ft_printf("Finish\n");
	ft_tout_free(map, 1);
	mlx_terminate(mlx);
	get_next_line(0, CLEAR);
	exit(0);
}
