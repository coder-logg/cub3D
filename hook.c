/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 03:43:48 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/22 11:29:19 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "cub3d.h"

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
	v->dir.x = v->dir.x * cos(cf*v->rotSpeed) - v->dir.y * sin(cf*v->rotSpeed);
	v->dir.y = oldDirX * sin(cf*v->rotSpeed) + v->dir.y * cos(cf*v->rotSpeed);
	v->plane.x = v->plane.x * cos(cf*v->rotSpeed) - v->plane.y * sin(cf*v->rotSpeed);
	v->plane.y = oldPlaneX * sin(cf*v->rotSpeed) + v->plane.y * cos(cf*v->rotSpeed);
	printf("dir[{x=%f, y=%f} plane{x=%f, y=%f}]\n", v->dir.x, v->dir.y, v->plane.x, v->plane.y);
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
	if (v->worldMap[(int)(v->pozition.x +cf * v->dir.x * v->moveSpeed)][(int)(v->pozition.y)] == false )
		v->pozition.x +=0.1 * (v->dir.x * (!si) + si * sin(v->plane.x)) * cf;
	if (v->worldMap[(int)(v->pozition.x)][(int)(v->pozition.y + cf * v->dir.y * v->moveSpeed)] == false)
		v->pozition.y +=0.1 * (v->dir.y * (!si) + si * sin(v->plane.y)) * cf;

	if (v->pozition.y <1.1)
		v->pozition.y =1.2  ;
	if (v->pozition.y > v->mappSize.y-1.1)
		v->pozition.y =v->mappSize.y-1.2  ;
	if (v->pozition.x <1.1)
		v->pozition.x =1.2 ;
	if (v->pozition.x >v->mappSize.x -1.1)
		v->pozition.x =v->mappSize.x -1.2;
	printf("dir[{x=%f, y=%f} plane{x=%f, y=%f}]<x=%f, y=%f>\n", v->dir.x, v->dir.y, v->plane.x, v->plane.y,v->pozition.x, v->pozition.y );
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
	(void) button;
	(void) x;
	(void) y;

	int keycode;

	if (button == 4)
		keycode = KEY_LEFT;
	else
		keycode = KEY_RIGHT;
	rotate(vars, keycode);
	printf("<%i, %i>\n", x, y);
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

int	close_prog(int keycode, t_vars *vars)
{
	(void) keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	//clear_mas2d(vars->mass.mass, vars->mass.param.max_y);//todo
	free(vars->img);
	free(vars->mlx);
//	free(vars);
	exit(0);
	return (0);
}


