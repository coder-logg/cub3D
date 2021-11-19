#include "libft/libft.h"

void	set_free(void **var, void *new)
{
	void	*tmp;

	if (var == NULL)
		return ;
	if (*var == new)
		return ;
	tmp = *var;
	*var = new;
	if (tmp)
		free(tmp);
}

void	*chmllc(void *ptr)
{
	if (ptr == NULL)
	{
		ft_putstr_fd("malloc error\n", 2);
		exit(1);
	}
	return (ptr);
}
