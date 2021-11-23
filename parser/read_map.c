/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphlogis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:28:53 by tphlogis          #+#    #+#             */
/*   Updated: 2021/11/23 02:31:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	read_first_map_line(t_vars *vars, int fd, char **line)
{
	int		gnl_ret;
	char	*tmp;

	tmp = NULL;
	gnl_ret = 1;
	while (gnl_ret)
	{
		gnl_ret = get_next_line(fd, line);
		if (!gnl_ret)
			error("Invalid file");
		tmp = chmllc(ft_strtrim((*line), " \t"));
		if (tmp[0])
		{
			free(tmp);
			break ;
		}
		free(tmp);
		free((*line));
	}
	parse_map_line(vars, (*line));
}

void	read_map(t_vars *vars, int fd)
{
	char	*line;
	int		gnl_ret;
	char	*tmp;

	gnl_ret = 1;
	tmp = NULL;
	vars->pozition.x = -1;
	vars->pozition.y = -1;
	ft_bzero(&vars->map_size, sizeof(vars->map_size));
	read_first_map_line(vars, fd, &line);
	while (gnl_ret)
	{
		gnl_ret = get_next_line(fd, &line);
		tmp = chmllc(ft_strtrim(line, " \t"));
		if (!tmp[0])
		{
			free(line);
			free(tmp);
			break ;
		}
		parse_map_line(vars, line);
		free(tmp);
	}
}
