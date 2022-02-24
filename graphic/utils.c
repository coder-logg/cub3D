/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 03:47:12 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/23 02:45:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

void	set_free(void **var, void *new)
{
	void	*tmp;

	if (var == NULL)
		return ;
	if (*var == new)
		return ;
	tmp = *var;
	*var = new;
	if (tmp)
		free(tmp);
}

void	*chmllc(void *ptr)
{
	if (ptr == NULL)
	{
		error("malloc error\n");
	}
	return (ptr);
}

void	error(char *msg)
{
	ft_putendl_fd("Error", 2);
	if (msg)
		ft_putendl_fd(msg, 2);
	exit(1);
}

void	init_point(t_point *point, double x, double y)
{
	ft_bzero(point, sizeof(*point));
	point->x = x;
	point->y = y;
}

int	arr_len(int **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i] != NULL)
		i++;
	return (i);
}
