/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:45:37 by cshanda           #+#    #+#             */
/*   Updated: 2021/05/06 11:45:38 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	size;
	char	*result;

	result = (char *) s;
	size = ft_strlen(s);
	i = 0;
	while (i < size)
	{
		if (*(result) == c)
			return (result);
		++i;
		++result;
	}
	if (*(result) == c)
		return (result);
	return (NULL);
}
