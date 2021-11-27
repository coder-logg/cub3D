/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 21:37:12 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/27 19:38:31 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <errno.h>

# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_UP				126
# define KEY_DOWAN			125
# define KEY_W				13
# define KEY_S				1
# define KEY_D				2
# define KEY_A				0
# define KEY_ESK			53
# define AMOUNT_TEXTURES	4
# define PITCH				100

typedef long		t_uint32;

typedef enum e_bool
{
	false,
	true
}				t_bool;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_pos2d
{
	int			x;
	int			y;
}					t_pos2d;

typedef struct s_point2D
{
	int				a;
	int				b;
	int				color;
}					t_point2d;

typedef struct s_point
{
	double				x;
	double				y;
}					t_point;

typedef struct s_dist
{
	t_point		delta;
	t_point		side;
}				t_dist;

typedef struct s_param_gem
{
	t_point	pos;
	t_point	dir;
	t_point	plane;
	t_point	ray_dir;
	t_pos2d	map;
	t_pos2d	step;
}				t_param_gem;

typedef struct s_param_x_a_r_s
{
	int		side;
	t_point	ray_dir;
	t_pos2d	x_a;
}				t_param_x_a_r_s;

typedef struct s_text
{
	long		*texs;
	t_pos2d		size;
}				t_text;

typedef struct s_key
{
	t_bool	str_r_key;
	t_bool	str_l_key;
	t_bool	up_key;
	t_bool	down_key;
	t_bool	left_key;
	t_bool	right_key;
}				t_key;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		*img;
	int			**world_map;
	int			color_floor;
	int			color_ceiling;
	t_uint32	**buff;
	t_text		texs[4];
	t_pos2d		display;
	t_point		pozition;
	t_point		dir;
	t_point		plane;
	double		move_speed;
	double		rot_speed;
	t_point		map_size;
	t_dist		dist;
	t_key		key;
	t_bool		mouse;
	int			mous_x;
}					t_vars;

void		geom_pixel_put(t_data *data, t_point2d point);
int			close_prog(int keycode, t_vars *vars);
int			key_hook(t_vars *vars);
int			mous_hook(int x, int y, t_vars *vars);
t_vars		*init_vars(t_vars *vars);
void		create_hook(t_vars *vars);
int			geom_pixel_get(t_data *data, int x, int y);
void		main_grafic(t_vars *vars);
t_text		geom_textyre_get(t_vars *vars, char *rel_p);
void		set_free(void **var, void *new);
void		*chmllc(void *ptr);
int			parser(t_vars *cub, char *path);
void		clear_var(t_vars *vars, t_bool del_img);
void		display_put(t_vars *vars);
void		create_y(t_vars *vars, t_point pos, t_param_x_a_r_s x);
void		create_side(t_vars *vars, t_pos2d *map, t_pos2d step, int *side);
void		clear_buff(t_vars *vars, t_param_gem *geom);
t_pos2d		write_dist_side(t_vars *vars, t_pos2d map,
				t_point pos, t_point ray_dr);
// parser
void		set_free(void **var, void *new);
void		*chmllc(void *ptr);
int			parser(t_vars *vars, char *path);
void		error(char *msg);
int			read_params(t_vars *vars, int fd);
int			get_line(int fd, char **dst);
void		invalid_map(char *str, int i, int j);
void		read_map(t_vars *vars, int fd);
void		init_point(t_point *point, double x, double y);
char		*chrdup(char ch, unsigned int len);
int			arr_len(int **arr);
int			**intarr_add(int **arr, size_t arrlen, int *new);
void		parse_map_line(t_vars *vars, char *line);
void		invalid_value(char *key, char *msg);
int			get_color(char *val, char *key);
void		print_vars(t_vars *vars);
int			**transporent(int **mass, int i_max);
int			hook_keypress(int keycode, t_vars *data);
int			hook_keyrel(int keycode, t_vars *data);
#endif
