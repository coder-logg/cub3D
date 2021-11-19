/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshanda <cshanda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:08:59 by cshanda           #+#    #+#             */
/*   Updated: 2021/06/14 18:31:58 by cshanda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGNL_H
# define LIBGNL_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_strchr_g(const char *s, int c);
size_t	ft_strlen_g(const char *str);
char	*ft_strdup_g(const char *src);
char	*ft_strjoinf_g(char *s1, const char *s2);
void	*ft_memcpy_g(void *dest, const void *src, size_t n);

#endif