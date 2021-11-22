//#include "cub3d.h"
#include <printf.h>
#include "cub3d.h"
#define START_POS 156

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

char	*chstr(char c)
{
	static char	chstr[2] = {0, 0};

	if (c >= 0)
		chstr[0] = c;
	return (chstr);
}

void invalid_map(char *str, int i, int j)
{
	char *tmp;
	char *tmp1;

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

void init_point(t_point *point, double x, double y)
{
	ft_bzero(point, sizeof(*point));
	point->x = x;
	point->y = y;
}

t_point get_offset(const t_vars *vars, int i, int j)
{
	t_point offset;

	ft_bzero(&offset, sizeof(offset));
	if (i > 0 && j > 0)
	{
		if (vars->world_map[j][i - 1] == 1) // may be error
			offset.x = 0.01;
		if (vars->world_map[j - 1][i] == 1) // may be error
			offset.y = 0.01;
	}
	return (offset);
}

void set_pos_params(t_vars *vars, char c, int i, int j)
{
	t_point offset = get_offset(vars, i, j);

	if (vars->pozition.x != -1 || vars->pozition.y != -1)
		invalid_map("Invalid input file: invalid map:"
					" multiple position definition", i, j);
	init_point(&vars->pozition, i + offset.x, j + offset.y);
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

int	arr_len(int **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i] != NULL)
		i++;
	return (i);
}

int	**extend_map(int **arr, int prev_len, int new_len)
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
		ft_memcpy(new_arr[i], arr[i], prev_len);
		j = prev_len;
		while (j < new_len)
			new_arr[i][j++] = -1;
		free(arr[i]);
	}
	free(arr);
	return (new_arr);
}

char	*chrdup(char ch, unsigned int len)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	ft_memset(new_str, ch, len);
	return (new_str);
}

void	parse_map_line(t_vars *vars, char *line)
{
	int	i;
	int	line_len;
	static int	j = 0;
	int	*world_map_nl;

	line_len = ft_strlen(line);
	i = -1;
	if (j == 0)
		vars->mapp_size.x = line_len;
	if (line_len > vars->mapp_size.x)
		vars->world_map = extend_map(vars->world_map, vars->mapp_size.x, line_len);
	else if (line_len < vars->mapp_size.x)
	{
//		char *buf = chmllc(ft_calloc(vars->mapp_size.x, sizeof(char)));
//		ft_memcpy(buf, line, line_len);
//		ft_memset(buf + line_len, ' ', vars->mapp_size.x - line_len);
		char *tmp = chmllc(chrdup(' ', vars->mapp_size.x - line_len));
		line = chmllc(ft_strjoin(line,tmp));
		line_len = vars->mapp_size.x;
	}
	world_map_nl = chmllc(ft_calloc(ft_strlen(line), sizeof(int)));
	vars->world_map = intarr_add(vars->world_map, j, world_map_nl);
//		error("Invalid map: lines with different lengths");
	while (++i < line_len)
	{
		if (!ft_strchr(" SWNE01", line[i]))
			invalid_map("Invalid input file: forbidden symbol in map", i, j);
		if (line[i] == ' ')
			world_map_nl[i] = -1;
		else if (line[i] == '0')
			world_map_nl[i] = 0;
		else if (line[i] == '1')
			world_map_nl[i] = 1;
		else if (ft_strchr("SWEN", line[i]))
		{
			set_pos_params(vars, line[i], i, j);
			world_map_nl[i] = 0;
		}
	}
	j++;
	vars->mapp_size.y = j;
}

void	read_map(t_vars *vars, int fd)
{
	char	*line;
	int		count_line;
	int		line_len;
	int		column_len;
	int		gnl_ret;
	char	*tmp;

	// обрезать карту по длинне самой длинной сроки и столбца
	// считывать до пустой строки или конца файла
	column_len = 0;
	line_len = 0;
	gnl_ret = 1;
	count_line = 0;
	tmp = NULL;
	vars->pozition.x = -1;
	vars->pozition.y = -1;
	vars->mapp_size.x = 0;
	vars->mapp_size.y = 0;
	while (gnl_ret)
	{
		gnl_ret = get_next_line(fd, &line);
		tmp = chmllc(ft_strtrim(line, " \t"));
		if (tmp[0])
		{
			free(tmp);
			break ;
		}
	}
	parse_map_line(vars, line);
	while (gnl_ret)
	{
		gnl_ret = get_next_line(fd, &line);
		tmp = chmllc(ft_strtrim(line, " \t"));
		if (!tmp[0])
		{
			free(tmp);
			break ;
		}
		parse_map_line(vars, line);
		free(line);
		free(tmp);
	}
}

//int	**check_map(int **map, int map_width, int map_height)
//{
//	int	i;
//	int	j;
//
//	i = 0;
//	while (i < map_height)
//	{
//		j = 0;
//		while (j < map_width)
//		{
//			if (map[i][j] == -1 )
//			j++;
//		}
//		i++;
//	}
//}

int	parser(t_vars *vars, char *path)
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
	vars->mlx = mlx_init();
	read_params(vars, fd);
	read_map(vars, fd);
	close(fd);
//	check_map( vars->world_map);
	printf("%p, %p, %p, %p,\n", vars->texs[0], vars->texs[1], vars->texs[2], vars->texs[3]);
	printf("floor - %d ceiling - %d\n", vars->color_floor, vars->color_ceiling);
	int i = 0;
	int j = 0;
	while (i < vars->mapp_size.y)
	{
		j = 0;
		printf("[");
		while (j < vars->mapp_size.x)
		{
			if (i == vars->pozition.y && j == vars->pozition.x)
				printf("\x1b[35m");
			printf("%2d", vars->world_map[i][j]);
			printf("\x1b[0m");
			j++;
		}
		printf("]\n");
		i++;
	}
	printf("%d, mapp_size.x = %d, mapp_size.y = %d\n", arr_len(vars->world_map), (int)vars->mapp_size.x, (int)vars->mapp_size.y);
	printf("%.2f %.2f\n", vars->pozition.x,  vars->pozition.y);
//	int inf_type = check_key(line);
//	vars->textures.ea = NULL;
	return (0);
}