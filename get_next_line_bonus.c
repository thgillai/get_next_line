/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:59:47 by thgillai          #+#    #+#             */
/*   Updated: 2020/02/18 11:17:30 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strndup(const char *s1, size_t n)
{
	int		i;
	char	*str;

	i = 0;
	if (s1 == NULL)
		return (ft_calloc(1, 1));
	if (!(str = (char *)malloc(sizeof(*str) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i] && i < (int)n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char *ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	if (*ptr == '\0' && c == '\0')
		return (ptr);
	return (NULL);
}

int		ft_line(int fd, char **line, char **str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = *line;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[i] == '\n')
	{
		if ((str[fd] = ft_strdup(ft_strchr(tmp, '\n') + 1)) == NULL)
			return (-1);
		if (!(*line = ft_strndup(tmp, i)))
		{
			free(str[fd]);
			return (-1);
		}
		free(tmp);
	}
	else
	{
		if (!(*line = ft_strdup(tmp)))
			return (-1);
		free(tmp);
	}
	return (1);
}

int		ft_read(int fd, char **line)
{
	char	*tmp;
	char	*buff;
	int		ret;

	ret = 1;
	while (ret > 0 && *line != NULL)
	{
		if (ft_strchr(*line, '\n'))
			break ;
		if (!(buff = ft_calloc(1, (BUFFER_SIZE + 1))))
			return (-1);
		ret = read(fd, buff, BUFFER_SIZE);
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
		free(buff);
	}
	if (*line != NULL)
		return (ret);
	else
		return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char		*str[FOPEN_MAX];
	int				flag;

	if (fd < 0 || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	*line = ft_strdup(str[fd]);
	if ((flag = ft_read(fd, line)) < 0)
	{
		free(*line);
		return (-1);
	}
	free(str[fd]);
	str[fd] = NULL;
	if (flag == 0 && str[fd] == NULL)
		return (0);
	return (ft_line(fd, line, str));
}
