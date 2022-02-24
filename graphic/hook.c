/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 03:43:48 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/28 11:10:51 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <printf.h>
#include "../cub3d.h"

void	rotate(t_vars *v, int keycode)
{
	int		cf;
	double	tdir_x;
	double	tpla_x;

	tdir_x = v->dir.x;
	tpla_x = v->plane.x;
	if (keycode == KEY_RIGHT)
		cf = -1;
	else
		cf = 1;
	v->dir.x = v->dir.x * cos(cf * v->rot_speed) - v->dir.y
		* sin(cf * v->rot_speed);
	v->dir.y = tdir_x * sin(cf * v->rot_speed) + v->dir.y
		* cos(cf * v->rot_speed);
	v->plane.x = v->plane.x * cos(cf * v->rot_speed) - v->plane.y
		* sin(cf * v->rot_speed);
	v->plane.y = tpla_x * sin(cf * v->rot_speed) + v->plane.y
		* cos(cf * v->rot_speed);
}

int	close_prog(int keycode, t_vars *vars)
{
	(void) keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	clear_var(vars, false);
	exit(0);
}
