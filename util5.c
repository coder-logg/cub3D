/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 18:06:37 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/21 09:40:30 by cshanda          ###   ########.fr       */
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
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 17, 1 << 17, close_prog17, vars);
	mlx_loop(vars->mlx);
}

void	clear_buff(t_vars *vars, t_param_gem *geom)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (int) vars->display.y)
	{
		x = -1;
		while (++x < (int)vars->display.x)
			vars->buff[y][x] = 0;
	}
	geom->dir = vars->dir;
	geom->pos = vars->pozition;
	geom->plane = vars->plane;
}

void	display_put(t_vars *vars)
{
	t_point2d	p;

	p.b = 0;
	while (p.b < vars->display.y)
	{
		p.a = 0;
		while (p.a < vars->display.x)
		{
			p.color = vars->buff[p.b][p.a];
			if (!p.color)
			{
				if (p.b < vars->gorizont)
					p.color = vars->ceilling_color;
				else
					p.color = vars->floor_color;
			}
			geom_pixel_put(vars->img, p);
			p.a++;
		}
		p.b++;
	}
}

int	create_side(t_vars *vars, t_pozition2d *map, t_pozition2d step)
{
	int	side;
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (vars->dist.side.x < vars->dist.side.y)
		{
			vars->dist.side.x += vars->dist.delta.x;
			map->x += step.x;
			side = 0;
		}
		else
		{
			vars->dist.side.y += vars->dist.delta.y;
			map->y += step.y;
			side = 1;
		}
		if (vars->world_map[map->x][map->y] > 0)
			hit = 1;
	}
	return (side);
}
