/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:52:13 by chajeon           #+#    #+#             */
/*   Updated: 2024/05/15 14:35:44 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/lib/get_next_line_bonus.h"
# include "../libft/lib/ft_printf.h"
# include "../libft/lib/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# define WIDTH 256
# define HEIGHT 256
# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

typedef struct s_map
{
	mlx_image_t	*gr;
	mlx_image_t	*ma;
	mlx_image_t	*md;
	mlx_image_t	*mw;
	mlx_image_t	*ms;
	mlx_image_t	*mons;
	mlx_image_t	*f_v;
	mlx_image_t	*f_h;
	mlx_image_t	*f_co;
	mlx_image_t	*fr;
	mlx_image_t	*p;
	mlx_t		*mlx;
	char		**map;
	char		**mapf;
	char		check;
	int			xlen;
	int			ylen;
	int			xstart;
	int			ystart;
	int			xporte;
	int			yporte;
	int			pcount;
	int			mcount;
	int			ecount;
	int			ccount;
	int			fpcount;
	int			fmcount;
	int			fecount;
	int			fccount;
	int			get_col;
	int			xss;
	int			yss;
	int			count;
	int			out;
}	t_map;

void	ft_tout_free(t_map *map, int check);
void	ft_print_error(char *message, t_map *map, int check);
void	ft_print_sans(char *message);
void	ft_free_arr(char **tofree);
int		ft_file_check(char	*filename);
void	ft_get_maps(char *filename, t_map *map);
void	ft_key_set(t_map *map);
void	ft_map_checker(t_map *map);
void	floodfill(int x, int y, char passed, t_map *map);
void	ft_set_images(t_map *map);
void	draw_img(mlx_image_t *img, int hss, int vss, t_map *map);
void	draw_map(t_map *map);
void	error(void);
void	ft_my_keyhook(mlx_key_data_t keydata, void *param);
void	ft_move_w(t_map *map);
void	ft_move_a(t_map *map);
void	ft_move_s(t_map *map);
void	ft_move_d(t_map *map);
void	renew_img_hss_a(t_map *map, int hss, int vss);
void	renew_img_hss_d(t_map *map, int hss, int vss);
void	renew_img_vss_w(t_map *map, int hss, int vss);
void	renew_img_vss_s(t_map *map, int hss, int vss);
void	hello_monster(t_map *map, mlx_t *mlx);
void	end_game(t_map *map, mlx_t *mlx);
#endif