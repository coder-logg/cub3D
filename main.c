/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:28:21 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/22 12:13:51 by tphlogis         ###   ########.fr       */
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
//	free(vars);
}

int	main(int argc, char **argv)
{
	t_vars			vars;

	(void)argc;
	if (argc != 2)
	{
		ft_putendl_fd("usage: ./cub3d [path to input file]", 1);
		return (0);
	}
	parser(&vars, argv[1]);
	init_vars(&vars, argv[1]);
	//	createTextyres(&vars);
	main_grafic(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img->img, 0, 0);
	create_hook(&vars);
	clear_var(&vars, true);
	return (0);
}
