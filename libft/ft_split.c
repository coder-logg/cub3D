/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 16:56:03 by cshanda           #+#    #+#             */
/*   Updated: 2021/06/26 07:19:50 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getsizemas(char const *s, char c)
{
	int	number_of_elems;

	number_of_elems = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
				s++;
			number_of_elems++;
			continue ;
		}
		s++;
	}
	return (number_of_elems);
}

static void	ft_freemass(char **mas)
{
	char	**mastmp;

	mastmp = mas;
	while (*mas)
	{
		free(*mas);
		mas++;
	}
	free(mastmp);
	mastmp = NULL;
}

static void	ft_generalsplit(char **mas, char const *s, char c, int n)
{
	int	count;
	int	len;

	count = 0;
	len = 0;
	while (count < n)
	{
		while (s[0] == c)
			s++;
		while (s[len] != c && s[len])
			len++;
		mas[count] = ft_calloc(len + 1, sizeof(char));
		if (!mas[count])
			ft_freemass(mas);
		ft_strlcpy(mas[count], s, len + 1);
		s += len;
		len = 0;
		count++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		n;

	if (!s)
		return (NULL);
	n = ft_getsizemas(s, c);
	result = ft_calloc(n + 1, sizeof(char *));
	if (!result)
		return (NULL);
	ft_generalsplit(result, s, c, n);
	return (result);
}

char	**ft_split_size(char const *s, char c, int *size)
{
	char	**result;
	int		n;

	if (!s)
		return (NULL);
	n = ft_getsizemas(s, c);
	result = ft_split(s, c);
	if (*size == 0)
		*size = n;
	else
	{
		if (*size != n)
		{
			write (1, "Found wrong line length. Exiting.\n", 34);
			exit(0);
		}
	}
	return (result);
}
