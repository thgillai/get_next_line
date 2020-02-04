/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 09:53:44 by thgillai          #+#    #+#             */
/*   Updated: 2020/02/04 16:10:31 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char	*buffer;
	int		nb_elem;

	if (!(buffer = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 1)
		return (-1);
}
