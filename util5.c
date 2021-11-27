/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 18:06:37 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/27 11:01:47 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_prog17(int keycode, t_vars *vars)
{
	(void) keycode;
	(void) vars;
	exit(0);
}

void	create_hook(t_vars *vars)
{
	mlx_mouse_hook(vars->win, mous_hook, vars);
	mlx_hook(vars->win, 2, 1L << 0, hook_keypress, vars);
	mlx_hook(vars->win, 3, 1L << 0, hook_keyrel, vars);
	mlx_hook(vars->win, 17, 1 << 17, close_prog17, vars);
	mlx_loop_hook(vars->mlx, &key_hook, vars);
	vars->img->img = mlx_new_image(vars->mlx, vars->display.x, vars->display.y);
	vars->img->addr = mlx_get_data_addr(vars->img->img \
			, &vars->img->bits_per_pixel, &vars->img->line_length \
			, &vars->img->endian);
	mlx_loop(vars->mlx);
}

void	clear_buff(t_vars *vars, t_param_gem *geom)
{
	int	x;
	int	y;

	y = -1;
	if (vars->buff)
	{
		while (++y < (int) vars->display.y)
		{
			x = -1;
			while (++x < (int)vars->display.x)
				vars->buff[y][x] = 0;
		}
	}
	geom->dir = vars->dir;
	geom->pos = vars->pozition;
	geom->plane = vars->plane;
}

void	display_put(t_vars *vars)
{
	t_point2d	p;
	t_bool		h;

	p.a = 0;
	while (p.a < vars->display.x)
	{
		p.b = 0;
		h = false;
		while (p.b < vars->display.y)
		{
			p.color = vars->buff[p.b][p.a];
			if (!p.color)
			{
				if (!h)
					p.color = vars->color_floor;
				else
					p.color = vars->color_ceiling;
			}
			else
				h = true;
			geom_pixel_put(vars->img, p);
			p.b++;
		}
		p.a++;
	}
}

void	create_side(t_vars *vars, t_pos2d *map, t_pos2d step
					, int	*side)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (vars->dist.side.x < vars->dist.side.y)
		{
			vars->dist.side.x += vars->dist.delta.x;
			if (!step.x)
				step.x = -1;
			map->x += step.x;
			*side = 0;
		}
		else
		{
			vars->dist.side.y += vars->dist.delta.y;
			if (!step.y)
				step.y = -1;
			map->y += step.y;
			*side = 1;
		}
		if (vars->world_map[map->y][map->x] > 0)
			hit = 1;
	}
}
