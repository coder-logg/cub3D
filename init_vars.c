/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 02:40:35 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/25 20:23:32 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	init_mlx_params(t_vars *vars, t_pos2d *d_size)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, (*d_size).x, (*d_size).y, "Cube3D");
	vars->img = malloc(sizeof(t_data));
	vars->img->img = mlx_new_image(vars->mlx, (*d_size).x, (*d_size).y);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&(vars->img->bits_per_pixel), &(vars->img->line_length),
			&(vars->img->endian));
}

t_vars	*init_vars(t_vars *vars)
{
	t_pos2d	d_size;
	int		i;

	d_size.x = 800;
	d_size.y = 600;
	vars->k=-1;
	vars->color_floor = -1;
	vars->color_ceiling = -1;
	vars->buff = chmllc(malloc(sizeof(t_uint32 *) * d_size.y));
	i = -1;
	while (++i < d_size.y)
		vars->buff[i] = chmllc(malloc(sizeof(t_uint32) * d_size.x));
	vars->display.x = d_size.x;
	vars->display.y = d_size.y;
	vars->gorizont = vars->display.y / 1.47;
	vars->move_speed = 0.1;
	vars->rot_speed = 0.1;
	init_mlx_params(vars, &d_size);
	return (vars);
}
