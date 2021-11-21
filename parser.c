//#include "cub3d.h"
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

char *get_line(int fd)
{
	static char	*line = NULL;
	int			gnl_ret;

	free(line);
	gnl_ret = 1;
	while (gnl_ret)
	{
		gnl_ret = get_next_line(fd, &line);
		if (!gnl_ret)
			break ;
		set_free((void **)&line, chmllc(ft_strtrim(line, " \t")));
		gnl_ret = 0;
		if (!line && !line[0])
			gnl_ret = 1;
	}
	return (line);
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
	t_bool s;

	i = -1;
	s = false;
	while (val[++i])
	{
		if (val[i] == ' ' || val[i] == '\t')
			continue;
		else if (val[i] == ',' && !s)
			s = true;
		else
			break;
	}
	if (ft_isdigit(val[i]))
		return (i);
	else
		return (-1);
}

int	get_color(char *val, char *key)
{
	int i;
	int j;
	int	rgb[3];

	j = 0;
	rgb[0] = -1;
	rgb[1] = -1;
	rgb[2] = -1;
	while(j < 3 && *val)
	{
		i = 0;
		while (val[i] && ft_isdigit(val[i]))
			i++;
		if (i == 0)
			invalid_value(key, "usage: F(C) R,G,B\n(R, G, B -- integer in range [0,255])");
		rgb[j] = ft_atoi(val);
		if (rgb[j] > 255)
			invalid_value(key, "R,G,B colors should be in range [0,255]");
		val += i;
		i = find_next_number(val);
		if (i == -1)
			invalid_value(key, NULL);
		val += i;
		j++;
	}
	if (rgb[2] == -1)
		invalid_value(key, NULL);
	return (rgb[0] && rgb[1] && rgb[2]);
}

t_bool check_path(char *path, char *key)
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

	if (inf_id == NO && !cub->texs[0] && check_path(val, key))
		cub->texs[0] = mlx_png_file_to_image(cub->mlx, val, ts, ts + 1);
	else if (inf_id == SO && !cub->texs[1] && check_path(val, key))
		cub->texs[1] = mlx_png_file_to_image(cub->mlx, val, ts, ts + 1);
	else if (inf_id == WE && !cub->texs[2] && check_path(val, key))
		cub->texs[2] = mlx_png_file_to_image(cub->mlx, val, ts, ts + 1);
	else if(inf_id == EA && !cub->texs[3] && check_path(val, key))
		cub->texs[3] = mlx_png_file_to_image(cub->mlx, val, ts, ts + 1);
	else if (inf_id == F && cub->color_floor == -1)
		cub->color_floor = get_color(val, key);
	else if (inf_id == C && cub->color_ceiling == -1)
		cub->color_ceiling = get_color(val, key);
}

int	read_params(t_vars *cub, int fd)
{
	char	*line;
	char	*key;
	int		inf_type;
	char	*val;

	cub->color_floor = -1;
	ft_bzero(cub->texs, 4);

	line = get_line(fd);
	key = get_key(line);
	inf_type = check_key(key);
	val = ft_substr(line + ft_strlen(key), 0, ft_strlen(line) - ft_strlen(key));
	chmllc(val);
	set_free((void **)&val, chmllc(ft_strtrim(val, " \t")));
	set_param_val(cub, inf_type, val, key);
	free(key);
	return (1);
}

int	parser(t_vars *cub, char *path)
{
	int		fd;
//	char	*line;
	char	*msg;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		if (errno == ENOTDIR)
			msg = "Path isn't valid";
		else
			msg = strerror(errno);
		error(msg);
	}
	read_params(cub, fd);
//	int inf_type = check_key(line);
//	cub->textures.ea = NULL;
	return (0);
}