/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphlogis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:53:04 by tphlogis          #+#    #+#             */
/*   Updated: 2021/11/24 14:02:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_point	get_offset(const t_vars *vars, int i, int j)
{
	t_point	offset;

	ft_bzero(&offset, sizeof(offset));
	if (i > 0 && j > 0)
	{
		if (vars->world_map[j][i - 1] == 1)
			offset.x = 0.5;
		if (vars->world_map[j - 1][i] == 1)
			offset.y = 0.5;
	}
	return (offset);
}

static void	set_pos_params(t_vars *vars, char c, int i, int j)
{
	if (vars->pozition.x != -1 || vars->pozition.y != -1)
		invalid_map("Invalid map: multiple position definition", i, j);
	init_point(&vars->pozition, i + get_offset(vars, i, j).x,
		j + get_offset(vars, i, j).y);
	if (c == 'N')
	{
		init_point(&vars->plane, 0, 0.66);
		init_point(&vars->dir, -1, 0);
	}
	else if (c == 'S')
	{
		init_point(&vars->plane, 0.038527, -0.658875);
		init_point(&vars->dir, 0.998295, 0.058374);
	}
	else if (c == 'W')
	{
		init_point(&vars->plane, -0.659994, 0.002921);
		init_point(&vars->dir, -0.004426, -0.999990);
	}
	else if (c == 'E')
	{
		init_point(&vars->plane, 0.659544, 0.024525);
		init_point(&vars->dir, -0.037158, 0.999309);
	}
}

static int	**extend_map(int **arr, int prev_len, int new_len)
{
	int	arr_length;
	int	i;
	int	j;
	int	**new_arr;

	arr_length = arr_len(arr);
	new_arr = chmllc(ft_calloc(arr_length + 1, sizeof(int *)));
	new_arr[arr_length] = NULL;
	i = -1;
	while (++i < arr_length)
	{
		new_arr[i] = chmllc(ft_calloc(new_len, sizeof(int)));
		ft_memcpy(new_arr[i], arr[i], prev_len * sizeof(int));
		j = prev_len;
		while (j < new_len)
			new_arr[i][j++] = -1;
		free(arr[i]);
	}
	free(arr);
	return (new_arr);
}

static int	extend_map_to_rect(t_vars *vars, int j, char **line)
{
	int			l_len;
	char		*tmp;

	l_len = ft_strlen(*line);
	tmp = NULL;
	if (j == 0)
		vars->map_size.x = l_len;
	if (l_len > vars->map_size.x)
	{
		vars->world_map = extend_map(vars->world_map, vars->map_size.x, l_len);
		vars->map_size.x = l_len;
	}
	else if (l_len < vars->map_size.x)
	{
		tmp = chmllc(chrdup(' ', vars->map_size.x - l_len));
		set_free((void **)line, chmllc(ft_strjoin((*line), tmp)));
		free(tmp);
		l_len = vars->map_size.x;
	}
	return (l_len);
}

void	parse_map_line(t_vars *vars, char *line)
{
	int			i;
	int			line_len;
	static int	j = 0;

	i = -1;
	line_len = extend_map_to_rect(vars, j, &line);
	vars->world_map = intarr_add(vars->world_map, j,
				chmllc(ft_calloc(line_len, sizeof(int))));
	while (++i < line_len)
	{
		if (!ft_strchr(" SWNE01", line[i]))
			invalid_map("Invalid map: forbidden symbol", i, j);
		if (line[i] == ' ')
			vars->world_map[j][i] = -1;
		else if (line[i] == '0' || ft_strchr("SWEN", line[i]))
			vars->world_map[j][i] = 0;
		else if (line[i] == '1')
			vars->world_map[j][i] = 1;
		if (ft_strchr("SWEN", line[i]))
			set_pos_params(vars, line[i], i, j);
	}
	free(line);
	j++;
	vars->map_size.y = j;
}
