/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:43:14 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/25 13:32:38 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	**transporent(int **mass, int i_max)
{
	int i;

	int **mas;

	i=i_max-1;
	mas = malloc(sizeof(int *)*i_max);
	if (!mas)
		error("malloc err");
	while(i>=0)
	{
		mas[i_max-i-1] = mass[i];
		i--;
	}

	return (mas);
}