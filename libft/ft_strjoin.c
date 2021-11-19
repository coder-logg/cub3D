/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:45:48 by cshanda           #+#    #+#             */
/*   Updated: 2021/05/08 14:53:26 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	void	*tmp;

	if (!s1 || !s2)
		return (0);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (0);
	tmp = result;
	tmp = ft_memcpy(tmp, s1, ft_strlen(s1));
	tmp += ft_strlen(s1);
	tmp = ft_memcpy(tmp, s2, ft_strlen(s2));
	tmp += ft_strlen(s2);
	*((char *)tmp) = '\0';
	return (result);
}
