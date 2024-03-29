/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:45:43 by cshanda           #+#    #+#             */
/*   Updated: 2021/05/06 11:45:43 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*t;
	long	i;

	i = 0;
	while (s[i] != '\0' && i >= 0)
		i++;
	t = malloc(i + 1);
	if (t == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && i >= 0)
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}
