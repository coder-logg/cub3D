/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 18:06:37 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/20 15:05:51 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	createHook(t_vars *vars)
{
	mlx_mouse_hook(vars->win, mous_hook, vars);
	mlx_hook(vars->win,  2, 0, key_hook, vars);
	mlx_loop(vars->mlx);
}
