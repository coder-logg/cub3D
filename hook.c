/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 03:43:48 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/27 12:27:25 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <printf.h>
#include "cub3d.h"

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

void	go_(t_vars *v, int keycode)
{
	int		cf;
	t_bool	si;
	int		i;
	int		j;

	cf = 1;
	si = false;
	if (keycode == KEY_DOWAN || keycode == KEY_S || keycode == KEY_A)
		cf = -1;
	if (keycode == KEY_D || keycode == KEY_A)
		si = true;
	i = (int)(v->pozition.y);
	j = (int)(v->pozition.x + cf * (v->dir.x * (!si) + si * sin(v->plane.x))
			* v->move_speed);
	if (v->world_map[i][j] == false)
		v->pozition.x += 0.1 * (v->dir.x * (!si) + si * sin(v->plane.x)) * cf;
	i = (int)(v->pozition.y + cf * (v->dir.y * (!si) + si * sin(v->plane.y))
			* v->move_speed);
	j = (int)(v->pozition.x);
	if (v->world_map[i][j] == false)
		v->pozition.y += 0.1 * (v->dir.y * (!si) + si * sin(v->plane.y)) * cf;
}

int	key_hook(t_vars *data)
{
	if (data->key.right_key)
		rotate(data, KEY_RIGHT);
	if (data->key.left_key)
		rotate(data, KEY_LEFT);
	if (data->key.up_key)
		go_(data, KEY_W);
	if (data->key.down_key)
		go_(data, KEY_S);
	if (data->key.strafeleft_key)
		go_(data, KEY_A);
	if (data->key.straferight_key)
		go_(data, KEY_D);
	main_grafic(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

int	mous_hook(int button, int x, int y, t_vars *vars)
{
	int	keycode;

	(void) button;
	(void) x;
	(void) y;
	if (button == 4)
		keycode = KEY_LEFT;
	else
		keycode = KEY_RIGHT;
	rotate(vars, keycode);
	main_grafic(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}

int	close_prog(int keycode, t_vars *vars)
{
	(void) keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	clear_var(vars, false);
	exit(0);
}
