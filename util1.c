/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 02:40:35 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/21 11:42:49 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "printf.h"
int worldMap[MAP_WIDTH][MAP_HEIGHT]=
		{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		};//todo;

void ft_assert(char *text)
{
	write(2,text , ft_strlen(text));
	write(2,"\n", 1);
	exit(0);
}

void createTextyres(t_vars *vars) ///todo
{
	vars->texs[0] = geom_textyre_get(vars, "./img/redbrick.xpm");
	vars->texs[1] = geom_textyre_get(vars, "./img/bluestone.xpm");
	vars->texs[2] = geom_textyre_get(vars, "./img/purplestone.xpm");
	vars->texs[3] = geom_textyre_get(vars, "./img/greystone.xpm");
}

t_vars	*create_vars(t_pozition2d d_size, char *path) ///todo
{
	t_vars	*vars;
	(void) path;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		ft_assert("malloc err");
	vars->world_map = malloc(sizeof(int *) * MAP_WIDTH * MAP_HEIGHT);
	if (!vars->world_map)
		ft_assert("malloc err");
	int i,j;
	i=0;
	while (i < MAP_WIDTH)
	{
		j=0;
		vars->world_map[i] = malloc(sizeof(int) * MAP_HEIGHT);
		if (!vars->world_map[i])
			ft_assert("malloc err");
		while (j < MAP_HEIGHT)
		{
			vars->world_map[i][j] =  worldMap[i][j];
			j++;
		}
		i++;
	}
	vars->buff = malloc(sizeof(t_uint32 *) * d_size.y);
	if (!vars->buff)
		ft_assert("malloc err");
	i=0;
	while (i< d_size.y)
	{
		vars->buff[i] = malloc(sizeof(t_uint32) * d_size.x);
		if (!vars->buff[i])
			ft_assert("malloc err");
		i++;
	}

	vars->mapp_size.x = MAP_WIDTH;///todo заменить на реальные размеры карты
	vars->mapp_size.y = MAP_HEIGHT;///
	vars->pozition.x=1.01; /// минимальная точка
	vars->pozition.y=1.01;///

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

	vars->floor_color = 0x000000; /// цвет пола
	vars->ceilling_color = 0xffffff; /// цвет потолка
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
	createTextyres(vars);
	return (vars);
}
