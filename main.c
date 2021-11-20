//#include "cub3d.h"
#include <printf.h>
#include "cub3d.h"

void	ClearVar(t_vars *vars)
{
	//clear_mas2d(vars->mass.mass, vars->mass.param.max_y);//todo
	free(vars->img->img);
	free(vars->img->addr);
	free(vars->img);
	free(vars->win);
	free(vars->mlx);
//	free(vars);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	(void)argc;
	if (argc != 2)
	{
		ft_putendl_fd("usage: ./cub3d [path to input file]", 1);
		return (0);
	}
//	parser(&vars, argv[1]);
//	printf("%p, %p, %p,", vars.texs[0], vars.texs[1], vars.texs[2]);
	init_vars(&vars, argv[1]);
	createTextyres(&vars);
	main_(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img->img, 0, 0);
	createHook(&vars);
//	ClearVar(&vars);
	return (0);
}
