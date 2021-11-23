/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:46:52 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/23 03:07:24 by tphlogis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*sub_str;
	char				*p;
	char				*p1;
	unsigned int		i;

	if (!s)
		return (0);
	sub_str = malloc(len + 1);
	if (!sub_str)
		return (0);
	i = 0;
	p1 = sub_str;
	p = (char *)s;
	while (i < len + start && i < ft_strlen(s))
	{
		if (i >= start)
			*p1++ = *p;
		p++;
		i++;
	}
	*p1 = '\0';
	return (sub_str);
}
