/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:01:18 by thgillai          #+#    #+#             */
/*   Updated: 2020/02/12 15:01:27 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	unsigned int i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	if (size == 0 || count == 0)
	{
		size = 1;
		count = 1;
	}
	if (!(ptr = (char *)malloc(sizeof(char) * (size * count))))
		return (0);
	i = 0;
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	if (s1)
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	if (s2)
		while (s2[j])
		{
			str[i + j] = s2[j];
			j++;
		}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	if (s1 == NULL)
		return (ft_calloc(1, 1));
	if (!(str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
