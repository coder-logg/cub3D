/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 03:43:48 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/25 20:50:24 by cshanda          ###   ########.fr       */
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
	j= (int)(v->pozition.x + cf * (v->dir.x * (!si) + si * sin(v->plane.x))
			* v->move_speed);
	if (v->world_map[i][j] == false)
		v->pozition.x += 0.1 * (v->dir.x * (!si) + si * sin(v->plane.x)) * cf;
	i = (int)(v->pozition.y + cf * (v->dir.y * (!si) + si * sin(v->plane.y))
			* v->move_speed);
	j = (int)(v->pozition.x);
	if (v->world_map[i][j] == false)
		v->pozition.y += 0.1 * (v->dir.y * (!si) + si * sin(v->plane.y)) * cf;
}

int	key_hook(int k, t_vars *vars)
{
	if (k == KEY_ESK)
		close_prog(k, vars);
	if (k == KEY_LEFT || k == KEY_RIGHT)
		rotate(vars, k);
	if (k == KEY_UP || k == KEY_DOWAN || k == KEY_W || k == KEY_S
		|| k == KEY_D || k == KEY_A)
		go_(vars, k);
	free(vars->img);
	vars->img = malloc(sizeof(t_data));
	vars->img->img = mlx_new_image(vars->mlx, vars->display.x,
			vars->display.y);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel, &vars->img->line_length,
			&vars->img->endian);
	main_grafic(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
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
	free(vars->img);
	vars->img = malloc(sizeof(t_data));
	vars->img->img = mlx_new_image(vars->mlx, vars->display.x, vars->display.y);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel,
			&vars->img->line_length, &vars->img->endian);
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
