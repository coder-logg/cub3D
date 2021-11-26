/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 10:11:13 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/26 09:44:33 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <printf.h>
#include "cub3d.h"

void	create_y_1(t_vars *vars, t_param_x_a_r_s x, t_pos2d draw
					, t_point l_w_x)
{
	t_pos2d		tex;
	double		step;
	double		tex_pos;
	t_uint32	color;
	int			y;

	tex.x = (int)(l_w_x.y * (double)(vars->texs[x.x_a.y].size.x));
	if (x.side == 0 && x.ray_dir.x > 0)
		tex.x = vars->texs[x.x_a.y].size.x - tex.x - 1;
	if (x.side == 1 && x.ray_dir.y < 0)
		tex.x = vars->texs[x.x_a.y].size.x - tex.x - 1;
	step = 1.0 * vars->texs[x.x_a.y].size.y / l_w_x.x;
	tex_pos = (draw.x - PITCH - vars->display.y / 2 + l_w_x.x / 2) * step;
	y = draw.x - 1;
	while (++y <= draw.y)
	{
		tex.y = (int)tex_pos;// & (vars->texs[x.x_a.y].size.y+vars->k);
		tex_pos += step;
		if (vars->texs[x.x_a.y].size.x * tex.y + tex.x >=0 &&
			vars->texs[x.x_a.y].size.x * tex.y + tex.x
			        < vars->texs[x.x_a.y].size.x*vars->texs[x.x_a.y].size.y)
			color = vars->texs[x.x_a.y].texs[vars->texs[x.x_a.y].size.x * tex.y + tex.x];
		if (!color)
			color = 1 ;
		vars->buff[y][x.x_a.x] = color;
	}
}

void	create_y(t_vars *vars, t_point pos, t_param_x_a_r_s x)
{
	double	perp_wall_dist;
	t_point	line_height_wall_x;
	t_pos2d	draw;

	if (x.side == 0)
		perp_wall_dist = (vars->dist.side.x - vars->dist.delta.x);
	else
		perp_wall_dist = (vars->dist.side.y - vars->dist.delta.y);
	line_height_wall_x.x = (int)(vars->display.y / perp_wall_dist);
	draw.x = -line_height_wall_x.x / 2 + vars->display.y / 2 + PITCH;
	if (draw.x < 0)
		draw.x = 0;
	draw.y = line_height_wall_x.x / 2 + vars->display.y / 2 + PITCH;
	if (draw.y >= (int)vars->display.y)
		draw.y = vars->display.y - 1;
	if (x.side == 0)
		line_height_wall_x.y = pos.y + perp_wall_dist * x.ray_dir.y;
	else
		line_height_wall_x.y = pos.x + perp_wall_dist * x.ray_dir.x;
	line_height_wall_x.y -= floor(line_height_wall_x.y);
	create_y_1(vars, x, draw, line_height_wall_x);
}

t_pos2d	write_dist_side(t_vars *vars, t_pos2d map, t_point pos, t_point ray_dr)
{
	t_pos2d	step;

	if (ray_dr.x < 0)
	{
		step.x = 0;
		vars->dist.side.x = (pos.x - map.x) * vars->dist.delta.x;
	}
	else
	{
		step.x = 1;
		vars->dist.side.x = (map.x + 1.0 - pos.x) * vars->dist.delta.x;
	}
	if (ray_dr.y < 0)
	{
		step.y = 0;
		vars->dist.side.y = (pos.y - map.y) * vars->dist.delta.y;
	}
	else
	{
		step.y = 1;
		vars->dist.side.y = (map.y + 1.0 - pos.y) * vars->dist.delta.y;
	}
	return (step);
}

void	is_ray_dir(t_point ray_dir, t_point *delta)
{
	if (ray_dir.x == 0)
		delta->x = 1e30;
	else
		delta->x = fabs(1 / ray_dir.x);
	if (ray_dir.y == 0)
		delta->y = 1e30;
	else
		delta->y = fabs(1 / ray_dir.y);
}

void	main_grafic(t_vars *vars)
{
	t_param_x_a_r_s	x;
	t_param_gem		geo;

	clear_buff(vars, &geo);
	x.x_a.x = -1;
	while (++x.x_a.x < (int)vars->display.x)
	{
		geo.ray_dir.x = geo.dir.x + geo.plane.x \
		* (2 * x.x_a.x / (double)vars->display.x - 1);
				geo.ray_dir.y = geo.dir.y + geo.plane.y \
				* (2 * x.x_a.x / (double)vars->display.x - 1);
						geo.map.x = (int)(geo.pos.x);
		geo.map.y = (int)(geo.pos.y);
		is_ray_dir(geo.ray_dir, &vars->dist.delta);
		geo.step = write_dist_side(vars, geo.map, geo.pos, geo.ray_dir);
		create_side(vars, &geo.map, geo.step, &x.side);
		x.x_a.y = x.side * (geo.step.y + 2) + (!x.side) * (geo.step.x);
		x.ray_dir = geo.ray_dir;
		create_y(vars, geo.pos, x);
	}
	display_put(vars);
}
