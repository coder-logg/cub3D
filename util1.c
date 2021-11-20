/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 02:40:35 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/19 23:32:01 by tphlogis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include "printf.h"

void ft_assert(char *text)
{
	write(2,text , ft_strlen(text));
	write(2,"\n", 1);
	exit(0);
}

t_vars	*create_vars(t_pozition2D d_size, char *path)
{
	t_vars	*vars;
	(void) path;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		ft_assert("malloc err");
	vars->worldMap = malloc(sizeof(int *) * mapWidth * mapHeight);
	if (!vars->worldMap)
		ft_assert("malloc err");
	int i,j;
	i=0;
	while (i < mapWidth)
	{
		j=0;
		vars->worldMap[i] = malloc(sizeof(int) * mapHeight);
		if (!vars->worldMap[i])
			ft_assert("malloc err");
		while (j < mapHeight)
		{
			vars->worldMap[i][j] =  worldMap[i][j];
			j++;
		}
		i++;
	}

	vars->buff = malloc(sizeof(Uint32 *) * d_size.y);
	if (!vars->buff)
		ft_assert("malloc err");
	i=0;
	while (i< d_size.y)
	{
		vars->buff[i] = malloc(sizeof(Uint32) * d_size.x);
		if (!vars->buff[i])
			ft_assert("malloc err");
		i++;
	}
	vars->pozition.x=22;
	vars->pozition.y=11.5;
	vars->plane.x = 0;
	vars->plane.y = 0.66;
	vars->dir.x = -1;
	vars->dir.y = 0;
	vars->display.x = d_size.x;
	vars->display.y = d_size.y;
	vars->texWidth = 64;
	vars->texHeight = 64;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, d_size.x, d_size.y, "Cube3D");
	vars->img = malloc(sizeof(t_data));
	vars->img->img = mlx_new_image(vars->mlx, d_size.x, d_size.y);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&(vars->img->bits_per_pixel), &(vars->img->line_length),
			&(vars->img->endian));
	return (vars);
}
