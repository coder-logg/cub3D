/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:28:21 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/20 03:02:32 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "libfdf.h"

void	ClearVar(t_vars *vars)
{
	//clear_mas2d(vars->mass.mass, vars->mass.param.max_y);//todo
	free(vars->img->img);
	free(vars->img->addr);
	free(vars->img);
	free(vars->win);
	free(vars->mlx);
	free(vars);
}

int	main(int argv, char **args)
{
	t_pozition2D	display_size;
	char			*path;
	t_vars			*vars;

	/*if (argv < 2)
		ft_assert("No path!");
	path = args[1];*/ //todo Раскоментить после добавления считывания файла
	path = malloc(1);
	path[0]=0;

	if (argv == 4)
	{
		display_size.x = ft_atoi(args[2]);
		display_size.y = ft_atoi(args[3]);
	}
	else
	{
		display_size.x = 800;
		display_size.y = 600;
	}
	vars = create_vars(display_size, path);
	main_(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	createHook(vars);
	ClearVar(vars);
	return (0);
}

