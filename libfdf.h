/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 21:37:12 by cshanda           #+#    #+#             */
/*   Updated: 2021/11/19 20:42:49 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFDF_H
# define LIBFDF_H
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft/libft.h"
# include "gnl/libgnl.h"

#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_UP  126
#define KEY_DOWAN  125
#define KEY_W  13
#define KEY_S  1
#define KEY_D  2
#define KEY_A  0
#define KEY_ESK 53

//#define texWidth 64
//#define texHeight 64
#define mapWidth 24
#define mapHeight 24
typedef long Uint32;
typedef signed int			t_i32;
typedef enum e_bool{
	false,
	true
} bool;
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
}					t_pozition2D;

typedef struct s_point2D
{
	int				a;
	int				b;
	int				color;
}					t_point2D;

typedef struct s_point
{
	double				x;
	double				y;

}					t_point;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	t_data			*img;
	int				**worldMap;
	Uint32			**buff;
	Uint32  		**texs;
	t_pozition2D	display;
	t_point			pozition;
	t_point			dir;
	t_point			plane;
	int				texWidth;
	int				texHeight;
}					t_vars;

void		geom_pixel_put(t_data *data, t_point2D point);
int			close_prog(int keycode, t_vars *vars);
int			key_hook(int k, t_vars *vars);
int			mous_hook(int button, int x, int y, t_vars *vars);
t_vars		*create_vars(t_pozition2D d_size, char *path);
void		createTextyres(t_vars *vars);
void		ft_assert(char *err);
void		createHook(t_vars *var);
int	geom_pixel_get(t_data *data, int x, int y);
void main_(t_vars *vars);
Uint32 *geom_textyre_get(t_vars *vars, char *relative_path);
int worldMap[mapWidth][mapHeight];//todo
#endif
