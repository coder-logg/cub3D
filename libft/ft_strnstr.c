/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:46:31 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/18 17:09:38 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;

	if (little[0] == '\0')
		return ((char *)big);
	if (ft_strlen(big) == 0)
		return (NULL);
	while (ft_strlen(little) <= (size_t)n)
	{
		if (*big == little[0])
		{
			i = 1;
			while (i > 0)
			{
				if (i == ft_strlen(little))
					return ((char *)big);
				if (big[i] != little[i])
					break ;
				++i;
			}
		}
		--n;
		++big;
	}
	return (NULL);
}
