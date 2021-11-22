/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 02:40:35 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/22 12:00:13 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "printf.h"
void ft_assert(char *text)
{
	write(2,text , ft_strlen(text));
	write(2,"\n", 1);
	exit(0);
}

t_vars *init_vars(t_vars *vars, char *path) ///todo
{
	(void) path;
	t_pozition2d	d_size;

	d_size.x = 800;
	d_size.y = 600;
//	vars = malloc(sizeof(t_vars));
//	if (!vars)
//		ft_assert("malloc err");
//	vars->world_map = malloc(sizeof(int *) * mapWidth * mapHeight);
//	if (!vars->world_map)
//		ft_assert("malloc err");
	int i;
//	i=0;
//	while (i < mapWidth)
//	{
//		j=0;
//		vars->world_map[i] = malloc(sizeof(int) * mapHeight);
//		if (!vars->world_map[i])
//			ft_assert("malloc err");
//		while (j < mapHeight)
//		{
//			vars->world_map[i][j] =  world_map[i][j];
//			j++;
//		}
//		i++;
//	}
	vars->buff = malloc(sizeof(t_uint32 *) * d_size.y);
	if (!vars->buff)
		ft_assert("malloc err");
	i = 0;
	while (i < d_size.y)
	{
		vars->buff[i] = malloc(sizeof(t_uint32) * d_size.x);
		if (!vars->buff[i])
			ft_assert("malloc err");
		i++;
	}

//	vars->mapp_size.x = mapWidth;///todo заменить на реальные размеры карты
//	vars->mapp_size.y = mapHeight;///
//	vars->pozition.x=1.1; /// минимальная точка
//	vars->pozition.y=1.1;///

	/// смотрим строго в верх
	///dir[{x=-1.000000, y=-0.000000} plane{x=-0.000000, y=0.660000}]
	///Смотрим в низ
	///dir[{x=0.998295, y=0.058374} plane{x=0.038527, y=-0.658875}]
	///смотрим на лево
	///dir[{x=-0.004426, y=-0.999990} plane{x=-0.659994, y=0.002921}]
	///сотрим на право
	///dir[{x=-0.037158, y=0.999309} plane{x=0.659544, y=0.024525}]

	vars->plane.x = 0;
	vars->plane.y = 0.66;
	vars->dir.x = -1;
	vars->dir.y = 0;

//	vars->Floor_color = 0x000000; /// цвет пола
//	vars->Ceilling_color = 0xffffff; /// цвет потолка
	vars->display.x = d_size.x;
	vars->display.y = d_size.y;
	vars->gorizont = vars->display.y/1.47;
	vars->move_speed = 1;
	vars->rot_speed = 0.1;
	vars->tex_width = 64;
	vars->tex_height = 64;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, d_size.x, d_size.y, "Cube3D");
	vars->img = malloc(sizeof(t_data));
	vars->img->img = mlx_new_image(vars->mlx, d_size.x, d_size.y);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&(vars->img->bits_per_pixel), &(vars->img->line_length),
			&(vars->img->endian));
//	createTextyres(vars);
	return (vars);
}
