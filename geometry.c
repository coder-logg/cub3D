/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 04:16:26 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/26 12:44:31 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	geom_pixel_put(t_data *data, t_point2d point)
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

t_text	geom_textyre_get(t_vars *vars, char *rel_p)
{
	t_data		*img_t;
	t_uint32	*img;
	t_pos2d		p;
	t_text		t;

	img_t = malloc(sizeof(t_data));
	if (!img_t)
		error("malloc error");
	img_t->img = mlx_xpm_file_to_image(vars->mlx, rel_p, &t.size.x, &t.size.y);
	if (img_t->img)
		error("Load texture error");
	img_t->addr = mlx_get_data_addr(img_t->img, &img_t->bits_per_pixel \
	, &img_t->line_length, &img_t->endian);
	img = malloc(t.size.y * t.size.x * sizeof(t_uint32));
	if (!img)
		error("malloc error");
	p.x = -1;
	while (++p.x < t.size.x)
	{
		p.y = -1;
		while (++p.y < t.size.y)
			img[t.size.x * p.y + p.x] = geom_pixel_get(img_t, p.x, p.y);
	}
	free(img_t->img);
	free(img_t);
	t.texs = img;
	return (t);
}
