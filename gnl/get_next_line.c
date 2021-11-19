/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:08:47 by cshanda           #+#    #+#             */
/*   Updated: 2021/06/20 01:02:06 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgnl.h"

static void	ft_offsetbuff_g(char *buffer, char *ptr)
{
	while (*ptr)
		*buffer++ = *ptr++;
	*buffer = '\0';
}

static char	*ft_getbuff_g(char *buffer, char **line)
{
	char	*ptr;

	ptr = ft_strchr_g(buffer, '\n');
	if (ptr)
		*ptr++ = '\0';
	*line = ft_strjoinf_g(*line, buffer);
	if (ptr)
	{
		ft_offsetbuff_g(buffer, ptr);
		return (buffer);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1] = "\0";
	char		*ptr;
	size_t		buffsize;

	buffsize = BUFFER_SIZE;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0 || line == 0)
		return (-1);
	*line = ft_strdup_g("");
	ptr = ft_getbuff_g(buffer, line);
	while (ptr == 0 && buffsize > 0)
	{
		buffsize = read(fd, buffer, buffsize);
		buffer[buffsize] = '\0';
		ptr = ft_getbuff_g(buffer, line);
		if (*line == 0)
			return (-1);
	}
	if (ptr == 0 && buffsize == 0)
		return (0);
	return (1);
}
