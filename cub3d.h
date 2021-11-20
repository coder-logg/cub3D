#ifndef CUB3D_H
# define CUB3D_H
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <string.h>
# include <stdbool.h>

# define WIN_HEIGHT 1000
# define WIN_WIDTH 1500

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_textures
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}				t_textures;

typedef struct s_matrix
{
	char	**matrix;
	int		m_width;
	int		m_height;
}				t_matrix;

typedef enum e_inf_type
{
	NO = 109,
	SO,
	WE,
	EA,
	F,
	C
}			t_inf_type;



typedef struct s_cub
{
	void		*mlx;
	void		*win;
	t_data		*img;
	t_textures	textures;
	int			color_floor;
	int			color_ceiling;
	int			**worldMap;
	long		**buff;
	long 		*texs[4];
}				t_vars;

int		parser(t_vars *cub, char *path);
void	set_free(void **var, void *new);
void	*chmllc(void *ptr);

#endif
