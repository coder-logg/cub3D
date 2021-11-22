/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 03:22:33 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/22 12:46:14 by tphlogis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

long	max(long a, long b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

long	min(long a, long b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
