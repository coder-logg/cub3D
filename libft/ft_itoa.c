/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 16:55:29 by cshanda           #+#    #+#             */
/*   Updated: 2021/05/08 16:55:29 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_power(int res, int n)
{
	long int	i;

	i = res;
	if (n == 0)
		return (1);
	while (n != 1)
	{
		i = i * res;
		n--;
	}
	return (i);
}

static int	ft_len(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_minus(int long n)
{
	return (n < 0);
}

static char	*ft_general(int long n, long int power, int len)
{
	char	*result;
	int		count;

	count = 0;
	if (ft_minus(n))
		result = malloc(sizeof(char) * len + 2);
	else
		result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	if (ft_minus(n))
	{
		n *= -1;
		result[count] = '-';
		count++;
	}
	while (len--)
	{
		result[count] = n / power + '0';
		n %= power;
		power /= 10;
		count++;
	}
	result[count] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	long int	nlong;
	long int	power;	
	int			len;
	char		*result;

	nlong = n;
	if (nlong == 0)
	{
		result = malloc(sizeof(char) * 2);
		if (!result)
			return(result);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	len = ft_len(nlong);
	power = ft_power(10, len - 1);
	result = ft_general(nlong, power, len);
	return (result);
}
