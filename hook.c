/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 03:43:48 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/19 00:28:58 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
double rotSpeed =0.1;//todo

void rotate(t_vars *v, int keycode)
{
	int		cf;
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = v->dir.x;
	oldPlaneX = v->plane.x;
	if (keycode == KEY_RIGHT)
		cf = -1;
	else
		cf = 1;
	v->dir.x = v->dir.x * cos(cf*rotSpeed) - v->dir.y * sin(cf*rotSpeed);
	v->dir.y = oldDirX * sin(cf*rotSpeed) + v->dir.y * cos(cf*rotSpeed);
	v->plane.x = v->plane.x * cos(cf*rotSpeed) - v->plane.y * sin(cf*rotSpeed);
	v->plane.y = oldPlaneX * sin(cf*rotSpeed) + v->plane.y * cos(cf*rotSpeed);
}

void go_(t_vars *v, int keycode)
{
	int cf;
	bool si;

	cf = 1;
	si = false;
	if (keycode == KEY_DOWAN || keycode == KEY_S || keycode == KEY_A)
		cf = -1;
	if (keycode == KEY_D || keycode == KEY_A)
		si = true;
	v->pozition.x +=0.1 * (v->dir.x * (!si) + si * sin(v->plane.x)) * cf;
	v->pozition.y +=0.1 * (v->dir.y * (!si) + si * sin(v->plane.y)) * cf;
}

int	key_hook(int k, t_vars *vars)
{
	if (k == KEY_ESK)
		close_prog(k, vars);
	if (k == KEY_LEFT || k == KEY_RIGHT)
		rotate(vars, k);
	if (k == KEY_UP || k == KEY_DOWAN ||  k == KEY_W || k == KEY_S
		|| k == KEY_D || k == KEY_A )
		go_(vars, k);
	free(vars->img);
	vars->img = malloc(sizeof(t_data));
	vars->img->img = mlx_new_image(vars->mlx, vars->display.x,
			vars->display.y);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel, &vars->img->line_length,
			&vars->img->endian);
	main_(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}

int	mous_hook(int button, int x, int y, t_vars *vars)//todo
{
	(void) x;
	(void) y;
	(void) vars;
	(void) button;
/*	if (button == 4)
		zoom(&(vars->zoom), increase, vars->delta);
	if (button == 5)
		zoom(&(vars->zoom), reduce, vars->delta);
	free(vars->img);
	vars->img = malloc(sizeof(t_data));
	vars->img->img = mlx_new_image(vars->mlx, vars->mass.display.x,
			vars->mass.display.y);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel, &vars->img->line_length,
			&vars->img->endian);
	main_(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	if (button == 3)
		close_prog(button, vars);*/
	return (0);
}

int	close_prog(int keycode, t_vars *vars)
{
	(void) keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	//clear_mas2d(vars->mass.mass, vars->mass.param.max_y);//todo
	free(vars->img);
	free(vars->mlx);
	free(vars);
	exit(1);
	return (0);
}


