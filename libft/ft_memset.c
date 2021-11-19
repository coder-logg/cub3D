/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:44:52 by cshanda           #+#    #+#             */
/*   Updated: 2021/05/06 11:44:54 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	char		*s_loc;

	s_loc = s;
	i = 0;
	while (i < n)
	{
		s_loc[i] = c;
		++i;
	}
	return (s_loc);
}
