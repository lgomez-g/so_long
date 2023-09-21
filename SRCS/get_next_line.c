/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:44:52 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/09/21 17:00:47 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			index;

	line = NULL;
	index = 0;
	if (fd < 0 || fd >= FOPEN_MAX || read(fd, buffer[fd], 0) < 0)
	{
		while (fd >= 0 && fd < FOPEN_MAX && buffer[fd][index])
			buffer[fd][index++] = '\0';
		return (NULL);
	}
	while (buffer[fd][0] || (read(fd, buffer[fd], BUFFER_SIZE)) > 0)
	{
		line = ft_strjoin(line, buffer[fd]);
		if (ft_manage_buffer(buffer[fd]))
			break ;
	}
	return (line);
}
