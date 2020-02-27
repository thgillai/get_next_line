/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:26:18 by thgillai          #+#    #+#             */
/*   Updated: 2020/02/27 15:50:44 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *reste)
{
	int		i;
	char	*line;

	i = 0;
	while (reste && reste[i] && reste[i] != '\n')
		i++;
	if (!(line = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (reste && reste[i] && reste[i] != '\n')
	{
		line[i] = reste[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_strjoinplus(char *reste, char *buff, int ret)
{
	char	*new;
	int		i;
	int		j;

	if (!(new = (char *)malloc((ft_strlen(reste) + ret + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (reste && reste[i])
	{
		new[i] = reste[i];
		i++;
	}
	j = 0;
	while (j < ret)
	{
		new[i + j] = buff[j];
		j++;
	}
	new[i + j] = '\0';
	if (reste)
		free(reste);
	return (new);
}

static char	*free_reste(char *reste, int *ret, int j)
{
	char	*new;
	int		i;

	*ret = 0;
	if ((i = is_line(reste)) < 0)
	{
		if (i == -1)
			free(reste);
		return (0);
	}
	if (!(new = (char *)malloc((ft_strlen(reste) - i + 1) * sizeof(char))))
	{
		*ret = -1;
		free(reste);
		return (0);
	}
	i++;
	while (reste[i + j])
	{
		new[j] = reste[i + j];
		j++;
	}
	new[j] = '\0';
	free(reste);
	return (new);
}

static int	get_next_l(int fd, char **line, unsigned int size)
{
	char		buff[size + 1];
	static char	*reste[FOPEN_MAX];
	int			ret;

	if (read(fd, buff, 0) < 0)
		return (-1);
	*line = NULL;
	ret = 0;
	while (is_line(reste[fd]) < 0 && (ret = read(fd, buff, size)))
		if (!(reste[fd] = ft_strjoinplus(reste[fd], buff, ret)))
			return (-1);
	if (!(*line = get_line(reste[fd])))
		return (-1);
	reste[fd] = free_reste(reste[fd], &ret, 0);
	if (!reste[fd])
		return (-1);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	unsigned int	size;

	if (BUFFER_SIZE <= 0 || !line || fd > FOPEN_MAX)
		return (-1);
	size = BUFFER_SIZE;
	return (get_next_l(fd, line, size));
}
