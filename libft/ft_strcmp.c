#include "libft.h"

int	ft_strcmp(char const *str1, char const *str2)
{
	int	i;

	if (str1 == NULL || str2 == NULL)
		return (0);
	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
