/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 03:47:12 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/22 12:13:51 by tphlogis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

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
		ft_putstr_fd("malloc error\n", 2);
		exit(1);
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
