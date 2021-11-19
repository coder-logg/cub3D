#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub cub;

	(void)argv;

	if (argc != 2)
	{
		ft_putendl_fd("usage: ./cub3d [path to input file]", 1);
		return (0);
	}
	cub.mlx = mlx_init();
	parser(&cub, argv[1]);
	printf("%p, %p, %p,", cub.texs[0], cub.texs[1], cub.texs[2]);
	return (0);
}
