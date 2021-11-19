/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:44:35 by cshanda           #+#    #+#             */
/*   Updated: 2021/05/06 11:44:37 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*d;

	d = dest;
	if (n == 0)
		return (d);
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		*((char *)dest) = *((char *)src);
		--n;
		++src;
		++dest;
	}
	return (d);
}
