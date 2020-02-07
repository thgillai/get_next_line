/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 09:54:28 by thgillai          #+#    #+#             */
/*   Updated: 2020/02/07 14:35:06 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		get_next_line(int fd, char **line);
int		ft_line(int fd, char **line, char **str);
int		ft_read(int fd, char **line);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *s1, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(char *str, size_t n);
size_t	ft_strlen(const char *str);

#endif
