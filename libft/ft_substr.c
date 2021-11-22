/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:46:52 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/22 12:13:51 by tphlogis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*subStr;
	char				*p;
	char				*p1;
	unsigned int		i;

	if (!s)
		return (0);
	subStr = malloc(len + 1);
	if (!subStr)
		return (0);
	i = 0;
	p1 = subStr;
	p = (char *)s;
	while (i < len + start && i < ft_strlen(s))
	{
		if (i >= start)
			*p1++ = *p;
		p++;
		i++;
	}
	*p1 = '\0';
	return (subStr);
}
