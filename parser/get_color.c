/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphlogis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:09:38 by tphlogis          #+#    #+#             */
/*   Updated: 2021/11/23 14:54:49 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	find_next_number(const char *val)
{
	int		i;
	t_bool	s;

	i = 0;
	s = false;
	while (val[i])
	{
		if (val[i] == ' ' || val[i] == '\t')
			continue ;
		else if (val[i] == ',' && !s)
			s = true;
		else
			break ;
		i++;
	}
	if (ft_isdigit(val[i]) || !val[i])
		return (i);
	else
		return (-1);
}

static int	rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	int	rgb;

	rgb = red;
	rgb <<= 8;
	rgb |= green;
	rgb <<= 8;
	rgb |= blue;
	return (rgb);
}

static void	set_arr_color(int *color)
{
	color[0] = -1;
	color[1] = -1;
	color[2] = -1;
}

int	get_color(char *val, char *key)
{
	int	ij[2];
	int	color[3];

	ij[1] = -1;
	set_arr_color((int *)color);
	while (++ij[1] < 3 && *val)
	{
		ij[0] = 0;
		while (val[ij[0]] && ft_isdigit(val[ij[0]]))
			ij[0]++;
		if (ij[0] == 0)
			invalid_value(key, "usage: F(C) R,G,B\n"
				"(R, G, B -- integer in range [0,255])");
		color[ij[1]] = ft_atoi(val);
		if (color[ij[1]] > 255)
			invalid_value(key, "R,G,B colors should be in range [0,255]");
		val += ij[0];
		ij[0] = find_next_number(val);
		if (ij[0] == -1)
			invalid_value(key, NULL);
		val += ij[0];
	}
	if (color[0] == -1 || color[1] == -1 || color[2] == -1)
		invalid_value(key, NULL);
	return (rgb(color[0], color[1], color[2]));
}
