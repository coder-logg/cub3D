/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:43:14 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/27 12:30:00 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <printf.h>
#include "cub3d.h"

int	**transporent(int **mass, int i_max)
{
	int	i;
	int	**mas;

	i = i_max - 1;
	mas = malloc(sizeof(int *) * i_max);
	if (!mas)
		error("malloc err");
	while (i >= 0)
	{
		mas[i_max - i - 1] = mass[i];
		i--;
	}
	free(mass);
	return (mas);
}

int	hook_keypress(int keycode, t_vars *data)
{
	printf("!\n");
	if (keycode == 53)
		return (close_prog(keycode, data));
	if (keycode == 2)
		data->key.str_r_key = true;
	else if (keycode == 0)
		data->key.str_l_key = true;
	else if (keycode == 13)
		data->key.up_key = true;
	else if (keycode == 1)
		data->key.down_key = true;
	else if (keycode == 123)
		data->key.left_key = true;
	else if (keycode == 124)
		data->key.right_key = true;
	return (0);
}

int	hook_keyrel(int keycode, t_vars *data)
{
	if (keycode == 2)
		data->key.str_r_key = false;
	else if (keycode == 0)
		data->key.str_l_key = false;
	else if (keycode == 13)
		data->key.up_key = false;
	else if (keycode == 1)
		data->key.down_key = false;
	else if (keycode == 123)
		data->key.left_key = false;
	else if (keycode == 124)
		data->key.right_key = false;
	return (0);
}
