/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphlogis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:55:25 by tphlogis          #+#    #+#             */
/*   Updated: 2021/11/24 19:27:36 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "../cub3d.h"

typedef enum e_inf_type
{
	NO = 109,
	SO,
	WE,
	EA,
	F,
	C
}			t_inf_type;

int	get_line(int fd, char **dst)
{
	static char	*line = NULL;
	int			gnl_ret;

	free(line);
	gnl_ret = 1;
	while (gnl_ret)
	{
		gnl_ret = get_next_line(fd, &line);
		if (!gnl_ret && !line)
			return (1);
		set_free((void **)&line, chmllc(ft_strtrim(line, " \t")));
		gnl_ret = 0;
		if (!line || !line[0])
		{
			free(line);
			gnl_ret = 1;
		}
	}
	*dst = line;
	return (0);
}

int	check_key(char *key)
{
	int	res;

	res = -1;
	if (!ft_strcmp(key, "NO"))
		res = WE;
	else if (!ft_strcmp(key, "SO"))
		res = EA;
	else if (!ft_strcmp(key, "WE"))
		res = SO;
	else if (!ft_strcmp(key, "EA"))
		res = NO;
	else if (!ft_strcmp(key, "F"))
		res = F;
	else if (!ft_strcmp(key, "C"))
		res = C;
	if (res == -1)
		error(ft_strjoin("Unknown type identifier: ", key));
	return (res);
}

t_bool	check_path(char *path, char *key)
{
	int		fd;
	char	*msg;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		if (errno == ENOTDIR)
			msg = "No such file or directory";
		else
			msg = strerror(errno);
		invalid_value(key, msg);
	}
	close(fd);
	return (true);
}

void	set_param_val(t_vars *cub, t_inf_type inf_id, char *val, char *key)
{
	if (inf_id >= NO && inf_id <= EA && check_path(val, key))
	{
		if (cub->texs[inf_id - NO])
			invalid_value(key, "Multiple identifier definition");
		cub->texs[inf_id - NO] = geom_textyre_get(cub, val);
	}
	else if (inf_id == F && cub->color_floor == -1)
		cub->color_floor = get_color(val, key);
	else if (inf_id == C && cub->color_ceiling == -1)
		cub->color_ceiling = get_color(val, key);
}

int	read_params(t_vars *vars, int fd)
{
	char	*line;
	char	*key;
	int		inf_type;
	char	*val;
	int		i;

	i = -1;
	while (++i < 6)
	{
		if (get_line(fd, &line) && i != 5)
			error("Invalid file format");
		key = (char *)max((long)ft_strchr(line, ' '),
				(long)ft_strchr(line, '\t'));
		if (key == NULL)
			error("Invalid file format");
		key = chmllc(ft_substr(line, 0, key - line));
		inf_type = check_key(key);
		val = chmllc(ft_substr(line + ft_strlen(key), 0,
					ft_strlen(line) - ft_strlen(key)));
		set_free((void **) &val, chmllc(ft_strtrim(val, " \t")));
		set_param_val(vars, inf_type, val, key);
		free(key);
		free(val);
	}
	return (1);
}
