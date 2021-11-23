/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphlogis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:54:23 by tphlogis          #+#    #+#             */
/*   Updated: 2021/11/23 02:54:27 by tphlogis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*chrdup(char ch, unsigned int len)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	ft_memset(new_str, ch, len);
	return (new_str);
}

void	invalid_map(char *str, int i, int j)
{
	char	*tmp;
	char	*tmp1;

	tmp = " [";
	tmp1 = chmllc(ft_itoa(i));
	tmp = chmllc(ft_strjoin(tmp, tmp1));
	set_free((void **)&tmp1, chmllc(ft_itoa(j)));
	set_free((void **)&tmp, ft_strjoin(tmp, " : "));
	set_free((void **)&tmp, ft_strjoin(tmp, tmp1));
	free(tmp1);
	set_free((void **)&tmp, ft_strjoin(tmp, "]"));
	error(chmllc(ft_strjoin(str, tmp)));
}

int	**intarr_add(int **arr, size_t arrlen, int *new)
{
	int	**new_arr;

	new_arr = chmllc(ft_calloc(arrlen + 2, sizeof(int *)));
	if (!new_arr || !new)
		return (NULL);
	if (arrlen >= 1 && arr)
		ft_memcpy(new_arr, arr, sizeof(int *) * arrlen);
	new_arr[arrlen] = new;
	new_arr[arrlen + 1] = NULL;
	if (arr)
		free(arr);
	return (new_arr);
}
