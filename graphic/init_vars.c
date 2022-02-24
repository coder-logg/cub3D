/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 02:40:35 by cshanda           #+#    #+#             */
/*   Updated: 2022/02/24 14:15:17 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

void	init_mlx_params(t_vars *vars, t_pos2d *d_size)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, (*d_size).x, (*d_size).y, "Cub3d");
	vars->img = malloc(sizeof(t_data));
	if (!vars->img)
		error("malloc err");
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
	vars->color_floor = -1;
	vars->color_ceiling = -1;
	vars->texs[0].texs = NULL;
	vars->texs[1].texs = NULL;
	vars->texs[2].texs = NULL;
	vars->texs[3].texs = NULL;
	vars->buff = chmllc(malloc(sizeof(t_uint32 *) * d_size.y));
	i = -1;
	while (++i < d_size.y)
		vars->buff[i] = chmllc(malloc(sizeof(t_uint32) * d_size.x));
	vars->display.x = d_size.x;
	vars->display.y = d_size.y;
	vars->move_speed = 0.081;
	vars->rot_speed = 0.02;
	vars->mous_x = 10;
	init_mlx_params(vars, &d_size);
	return (vars);
}
