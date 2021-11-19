/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:08:37 by cshanda           #+#    #+#             */
/*   Updated: 2021/06/14 18:32:42 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgnl.h"

void	*ft_memcpy_g(void *dest, const void *src, size_t n)
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

size_t	ft_strlen_g(const char *s)
{
	int		n;

	n = 0;
	while (s[n])
		++n;
	return (n);
}

char	*ft_strdup_g(const char *s)
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

char	*ft_strchr_g(const char *s, int c)
{
	size_t	i;
	size_t	size;
	char	*result;

	result = (char *) s;
	size = ft_strlen_g(s);
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

char	*ft_strjoinf_g(char *s1, char const *s2)
{
	char	*result;
	void	*tmp;

	if (!s1 || !s2)
		return (0);
	result = malloc(ft_strlen_g(s1) + ft_strlen_g(s2) + 1);
	if (!result)
		return (0);
	tmp = result;
	tmp = ft_memcpy_g(tmp, s1, ft_strlen_g(s1));
	tmp += ft_strlen_g(s1);
	tmp = ft_memcpy_g(tmp, s2, ft_strlen_g(s2));
	tmp += ft_strlen_g(s2);
	*((char *)tmp) = '\0';
	free(s1);
	return (result);
}
