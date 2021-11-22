/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 04:16:26 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/22 11:29:19 by tphlogis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	geom_pixel_put(t_data *data, t_point2D point)
{
	char	*dst;

	dst = data->addr + (point.b * data->line_length + point.a
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = point.color;
}
int	geom_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

Uint32 *geom_textyre_get(t_vars *vars, char *relative_path)
{
	t_data *img_t;
	int		img_width;
	int		img_height;
	Uint32 *img;
	t_pozition2D p;

	img_t = malloc(sizeof(t_data));
	img_t->img = mlx_xpm_file_to_image(vars->mlx, relative_path,
									   &img_width, &img_height);
	if (!img_t->img)
		ft_assert("Err: not get texture");
	img_t->addr = mlx_get_data_addr(
			img_t->img,
			&img_t->bits_per_pixel,
			&img_t->line_length,
			&img_t->endian);
	img = malloc(img_width*img_height* sizeof(Uint32));
	if (!img)
		ft_assert("malloc eror");
	p.x = 0;
	p.y = 0;
	while (p.x < vars->texWidth)
	{
		p.y = 0;
		while (p.y < vars->texHeight)
		{
			img[vars->texWidth * p.y + p.x] = geom_pixel_get(img_t,p.x,p.y);
			p.y++;
		}
		p.x++;
	}
	free(img_t->img);
	free(img_t);
	return (img);
}