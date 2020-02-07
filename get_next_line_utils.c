/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 09:54:10 by thgillai          #+#    #+#             */
/*   Updated: 2020/02/07 14:06:07 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(char *str, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = '\0';
		i++;
	}
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (src == NULL || dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (!(result = malloc(size * count)))
		return (NULL);
	ft_bzero(result, size * count);
	if (result == 0)
		return (NULL);
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			j;
	int			size;
	char		*str;

	i = 0;
	j = 0;
	str = NULL;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = malloc(sizeof(char *) * size)))
		return (NULL);
	while (i < s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (i < s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (c == '\0')
		return (str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}
