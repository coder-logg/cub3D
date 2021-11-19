/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:46:02 by cshanda           #+#    #+#             */
/*   Updated: 2021/05/06 11:46:04 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	const char	*s;
	size_t		n_;
	int			g;

	s = src;
	n_ = n;
	if (!dest)
		return (0);
	if (n_ != 0)
	{
		while (--n_ != 0)
		{
			g = (*dest++ = *s++) == '\0';
			if (g)
				break ;
		}
	}
	if (n_ == 0)
	{
		if (n != 0)
			*dest = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}
