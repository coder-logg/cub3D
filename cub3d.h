/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 21:37:12 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/22 12:13:53 by tphlogis         ###   ########.fr       */
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
# define MAP_WIDTH			24 /// todo удалить
# define MAP_HEIGHT			24 /// todo удалить
# define PITCH				100

typedef long		t_uint32;
typedef signed int	t_i32;

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

typedef struct s_pozition2D
{
	int			x;
	int			y;
}					t_pozition2d;

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
	t_point			pos;
	t_point			dir;
	t_point			plane;
	t_point			ray_dir;
	t_pozition2d	map;
	t_pozition2d	step;
}				t_param_gem;

typedef struct s_param_x_a_r_s
{
	int				side;
	t_point			ray_dir;
	t_pozition2d	x_a;
}				t_param_x_a_r_s;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	t_data			*img;
	int				**world_map;
	int				color_floor;
	int				color_ceiling;
	t_uint32		**buff;
	long			*texs[AMOUNT_TEXTURES];
	t_pozition2d	display;
	t_point			pozition;
	t_point			dir;
	t_point			plane;
	int				tex_width;
	int				tex_height;
	int				floor_color;
	int				ceilling_color;
	double			gorizont;
	double			move_speed;
	double			rot_speed;
	t_point			mapp_size;
	t_dist			dist;
}					t_vars;

void			geom_pixel_put(t_data *data, t_point2d point);
int				close_prog(int keycode, t_vars *vars);
int				key_hook(int k, t_vars *vars);
int				mous_hook(int button, int x, int y, t_vars *vars);
t_vars			*init_vars(t_vars *vars, char *path);
void			createTextyres(t_vars *vars);
void			ft_assert(char *err);
void			create_hook(t_vars *vars);
int				geom_pixel_get(t_data *data, int x, int y);
void			main_grafic(t_vars *vars);
t_uint32		*geom_textyre_get(t_vars *vars, char *relative_path);
t_vars			*create_vars(t_pozition2d d_size, char *path);
void			set_free(void **var, void *new);
void			*chmllc(void *ptr);
int				parser(t_vars *cub, char *path);
void			clear_var(t_vars *vars, t_bool del_img);
void			display_put(t_vars *vars);
void			create_y(t_vars *vars, t_point pos, t_param_x_a_r_s x);
void			create_side(t_vars *vars, t_pozition2d *map, t_pozition2d step \
, int *side);
void			clear_buff(t_vars *vars, t_param_gem *geom);
t_pozition2d	write_dist_side(t_vars *vars, t_pozition2d map, t_point pos \
, t_point ray_dir);

void	set_free(void **var, void *new);
void	*chmllc(void *ptr);
int		parser(t_vars *vars, char *path);
void	error(char *msg);
int		read_params(t_vars *vars, int fd);
int		get_line(int fd, char **dst);

#endif
