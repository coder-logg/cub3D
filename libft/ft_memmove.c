/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:44:43 by cshanda           #+#    #+#             */
/*   Updated: 2021/05/06 11:44:46 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*copy;
	void	*d;
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = dest;
	copy = malloc(n);
	if (copy)
	{
		i = 0;
		while (i < n)
		{
			((char *)copy)[i] = ((char *)src)[i];
			++i;
		}
		i = 0;
		while (i < n)
		{
			((char *)d)[i] = ((char *)copy)[i];
			++i;
		}
		free(copy);
	}
	return (dest);
}
