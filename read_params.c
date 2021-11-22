#include <printf.h>
#include "cub3d.h"

typedef enum e_inf_type
{
	NO = 109,
	SO,
	WE,
	EA,
	F,
	C
}			t_inf_type;

char 	*get_key(char *line)
{
	char	*ptr;

	ptr = (char *)max((long)ft_strchr(line, ' '), (long)ft_strchr(line, '\t'));
	return chmllc(ft_substr(line, 0, ptr - line));
}

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
			gnl_ret = 1;
	}
	*dst = line;
	return (0);
}

void	error(char *msg)
{
	ft_putendl_fd("Error", 2);
	if (msg)
		ft_putendl_fd(msg, 2);
	exit(1);
}

int check_key(char *key)
{
	int	res;

	res = -1;
	if (!ft_strcmp(key, "NO"))
		res = NO;
	else if (!ft_strcmp(key, "SO"))
		res = SO;
	else if (!ft_strcmp(key, "WE"))
		res = WE;
	else if(!ft_strcmp(key, "EA"))
		res = EA;
	else if (!ft_strcmp(key, "F"))
		res = F;
	else if (!ft_strcmp(key, "C"))
		res = C;
	if (res == -1)
		error(ft_strjoin("Unknown type identifier: ", key));
	return (res);
}

void	invalid_value(char *key, char *msg)
{
	key = chmllc(ft_strjoin("Invalid value for identifier: ", key));
	ft_putendl_fd(key, 2);
	if (msg)
		ft_putendl_fd(msg, 2);
	free(key);
	exit(1);
}

int	find_next_number(const char *val)
{
	int i;
	bool s;

	i = 0;
	s = false;
	while (val[i])
	{
		if (val[i] == ' ' || val[i] == '\t')
			continue;
		else if (val[i] == ',' && !s)
			s = true;
		else
			break;
		i++;
	}
	if (ft_isdigit(val[i]) || !val[i])
		return (i);
	else
		return (-1);
}

int rgb(unsigned char red, unsigned char green,  unsigned char blue)
{
	int rgb;

	rgb = red;
	rgb <<= 8;
	rgb |= green;
	rgb <<= 8;
	rgb |= blue;

	return (rgb);
}

int	get_color(char *val, char *key)
{
	int i;
	int j;
	int	color[3];

	j = 0;
	color[0] = -1;
	color[1] = -1;
	color[2] = -1;
	while(j < 3 && *val)
	{
		i = 0;
		while (val[i] && ft_isdigit(val[i]))
			i++;
		if (i == 0)
			invalid_value(key, "usage: F(C) R,G,B\n(R, G, B -- integer in range [0,255])");
		color[j] = ft_atoi(val);
		if (color[j] > 255)
			invalid_value(key, "R,G,B colors should be in range [0,255]");
		val += i;
		i = find_next_number(val);
		if (i == -1)
			invalid_value(key, NULL);
		val += i;
		j++;
	}
	if (color[0] == -1 || color[1] == -1|| color[2] == -1)
		invalid_value(key, NULL);
	return (rgb(color[0], color[1], color[2]));
}

bool check_path(char *path, char *key)
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

void set_param_val(t_vars *cub, t_inf_type inf_id, char *val, char *key)
{
	int		ts[2];

	if (inf_id >= NO && inf_id <= EA && check_path(val, key))
	{
		if (cub->texs[inf_id - NO])
			invalid_value(key, "Multiple identifier definition");
		cub->texs[inf_id - NO] = mlx_xpm_file_to_image(cub->mlx, val, ts, ts + 1);
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

	i = 0;
	vars->texs[0] = NULL;
	vars->texs[1] = NULL;
	vars->texs[2] = NULL;
	vars->texs[3] = NULL;
	vars->color_floor = -1;
	vars->color_ceiling = -1;
	//	vars->texs[4] = NULL;
	while (i < 6)
	{
		if(get_line(fd, &line) && i != 5)
			error("Invalid file format");
		key = get_key(line);
		inf_type = check_key(key);
		val = ft_substr(line + ft_strlen(key), 0,
						ft_strlen(line) - ft_strlen(key));
		chmllc(val);
		set_free((void **) &val, chmllc(ft_strtrim(val, " \t")));
		set_param_val(vars, inf_type, val, key);
		free(key);
		i++;
	}
	return (1);
}