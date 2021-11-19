/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:45:56 by cshanda           #+#    #+#             */
/*   Updated: 2021/05/06 11:45:58 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	slen;

	len = 0;
	slen = ft_strlen(src);
	while (*dest && size > 0)
	{
		dest++;
		len++;
		size--;
	}
	while (*src && size-- > 1)
		*dest++ = *src++;
	if (size == 0 || *src == '\0')
		*dest = '\0';
	return (slen + len);
}
