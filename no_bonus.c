/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:13:09 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/28 12:56:03 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	go_(t_vars *v, int keycode)
{
	int		cf;
	t_bool	si;
	int		i;

	cf = 1;
	si = false;
	if (keycode == KEY_DOWAN || keycode == KEY_S || keycode == KEY_A)
		cf = -1;
	if (keycode == KEY_D || keycode == KEY_A)
		si = true;
	i = (int)(v->pozition.x + cf * (v->dir.x * (!si) + si * sin(v->plane.x)) \
		* v->move_speed);
	if (v->map_size.x - 1 > i && i > 1 \
			&& v->world_map[(int)(v->pozition.y)][i] != -1)
		v->pozition.x += v->move_speed \
			* (v->dir.x * (!si) + si * sin(v->plane.x)) * cf;
	i = (int)(v->pozition.y + cf * (v->dir.y * (!si) + si * sin(v->plane.y)) \
		* v->move_speed);
	if (v->map_size.y -1 > i && i > 0)
		v->pozition.y += v->move_speed \
			* (v->dir.y * (!si) + si * sin(v->plane.y)) * cf;
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
	if (data->key.str_l_key)
		go_(data, KEY_A);
	if (data->key.str_r_key)
		go_(data, KEY_D);
	if (data->key.right_key || data->key.left_key || data->key.up_key \
		|| data->key.down_key || data->key.str_l_key || data->key.str_r_key)
	{
		main_grafic(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	}
	return (0);
}

void	create_hook(t_vars *vars)
{
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
