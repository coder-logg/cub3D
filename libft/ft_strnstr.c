/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:46:31 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/22 12:13:51 by tphlogis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *s1, char *s2, int lenghth)
{
	size_t	i;

	if (s2[0] == '\0')
		return ((char *)s1);
	if (ft_strlen(s1) == 0)
		return (NULL);
	while (ft_strlen(s2) <= (size_t)lenghth)
	{
		if (*s1 == s2[0])
		{
			i = 1;
			while (i > 0)
			{
				if (i == ft_strlen(s2))
					return ((char *)s1);
				if (s1[i] != s2[i])
					break ;
				++i;
			}
		}
		--lenghth;
		++s1;
	}
	return (NULL);
}
