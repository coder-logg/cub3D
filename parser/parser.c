/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphlogis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 01:28:57 by tphlogis          #+#    #+#             */
/*   Updated: 2021/11/26 23:58:27 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_bool	check_around(int **map, t_point map_size, int ln, int col)
{
	if ((map[ln][col] == 0 && ln > 0 && ln < map_size.y - 1
		&& col > 0 && col < map_size.x - 1
		&& ((map[ln - 1][col] == 0 || map[ln - 1][col] == 1)
		&& (map[ln + 1][col] == 0 || map[ln + 1][col] == 1)
		&& (map[ln][col - 1] == 0 || map[ln][col - 1] == 1)
		&& (map[ln][col + 1] == 0 || map[ln][col + 1] == 1)
	&& (map[ln - 1][col - 1] == 0 || map[ln - 1][col - 1] == 1)
	&& (map[ln + 1][col + 1] == 0 || map[ln + 1][col + 1] == 1)
	&& (map[ln + 1][col - 1] == 0 || map[ln + 1][col - 1] == 1)
	&& (map[ln - 1][col + 1] == 0 || map[ln - 1][col + 1] == 1)))
	|| map[ln][col] == 1 || map[ln][col] == -1)
		return (true);
	return (false);
}

void	check_map(int **map, t_point map_size)
{
	int	i;
	int	j;

	i = 0;
	if (map_size.y < 3 || map_size.x < 3)
		error("Invalid map: map at least should be have size 3x3");
	while (i < map_size.y)
	{
		j = -1;
		while (++j < map_size.x)
		{
			if (!check_around(map, map_size, i, j)
				|| ((i == 0 || i == map_size.y - 1) && map[i][j] == 0))
				invalid_map("Invalid map: need border around", i, j);
		}
		i++;
	}
}

int	parser(t_vars *vars, char *path)
{
	int		fd;
	char	*msg;

	if (ft_strcmp(path + ft_strlen(path) - 4, ".cub"))
		error("Invalid file extension");
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		if (errno == ENOTDIR)
			msg = "Path isn't valid";
		else
			msg = strerror(errno);
		error(msg);
	}
	vars->mlx = mlx_init();
	read_params(vars, fd);
	read_map(vars, fd);
	close(fd);
	check_map(vars->world_map, vars->map_size);
	if (vars->pozition.x == -1 || vars->pozition.y == -1)
		error("Invalid map: player position wasn't defined");
	return (0);
}
