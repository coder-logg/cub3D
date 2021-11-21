/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 18:06:37 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/21 03:50:48 by cshanda          ###   ########.fr       */
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
