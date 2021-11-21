/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:28:21 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/21 04:20:49 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_var(t_vars *vars, t_bool del_img)
{
	int	i;

	i = 0;
	while (i < AMOUNT_TEXTURES)
		free(vars->texs[i++]);
	i = 0;
	while (i < vars->display.y)
		free(vars->buff[i++]);
	free(vars->buff);
	i = 0;
	while (i < vars->mapp_size.y)
		free(vars->world_map[i++]);
	free(vars->world_map);
	if (del_img)
	{
		free(vars->img->img);
		free(vars->img->addr);
	}
	free(vars->img);
	if (del_img)
		free(vars->win);
	free(vars->mlx);
	free(vars);
}

int	main(int argv, char **args)
{
	t_pozition2d	display_size;
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
	main_grafic(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	create_hook(vars);
	clear_var(vars, true);
	return (0);
}
