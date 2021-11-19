/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:41:59 by cshanda           #+#    #+#             */
/*   Updated: 2021/05/06 11:41:59 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t				i;
	unsigned long		result;
	unsigned long		resulttmp;
	int					pozitiv;

	if (*nptr == '\0')
		return (0);
	result = 0;
	pozitiv = 1;
	i = 0;
	while (nptr[i] < 33 && nptr[i] != '\e')
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
		pozitiv = 1 - 2 * (nptr[i++] == '-');
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		resulttmp = result;
		result = 10 * result + (nptr[i] - '0');
		if (resulttmp > result)
			return ((-1 - pozitiv) / 2);
		++i;
	}
	return (pozitiv * result);
}
