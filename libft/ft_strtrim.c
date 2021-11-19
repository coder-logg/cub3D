/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:46:44 by cshanda           #+#    #+#             */
/*   Updated: 2021/05/06 11:46:46 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_gopoint(void *val, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		val++;
		i++;
	}
	return (val);
}

static int	ft_chekchar(const char c, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(set);
	i = 0;
	while (i < len)
	{
		if (*set == c)
			return (i);
		i++;
		set++;
	}
	return (-1);
}

static char	*ft_searctrimstart(char const *s, char const*set)
{
	while (*s != '\0')
	{
		if (ft_chekchar(*s, set) == -1)
			break ;
		s++;
	}
	return ((char *)s);
}

static char	*ft_searctrimend(char const *s, char const *set)
{
	char	*end;

	end = (char *)ft_gopoint((char *)s, ft_strlen((char *)s)) - 1;
	while (end + 1 != s)
	{
		if (ft_chekchar(*end, set) == -1)
			break ;
		end--;
	}
	end++;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	char	*tmp;
	char	*end;

	if (!s1 || !set)
		return (0);
	s1 = ft_searctrimstart(s1, set);
	end = ft_searctrimend(s1, set);
	result = malloc(ft_strlen(s1) - ft_strlen(end) + 1);
	if (!result)
		return (0);
	tmp = result;
	while (s1 != end)
	{
		*tmp = *s1;
		tmp++;
		s1++;
	}
	*tmp = '\0';
	return (result);
}
