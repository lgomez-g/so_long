/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:45:11 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/09/21 17:00:38 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


bool	ft_manage_buffer(char *buffer)
{
	size_t	read_index;
	size_t	write_index;
	bool	found_nl;

	read_index = 0;
	write_index = 0;
	found_nl = false;
	while (buffer[read_index])
	{
		if (buffer[read_index] == '\n')
		{
			found_nl = true;
			read_index++;
			break ;
		}
		read_index++;
	}
	while (buffer[read_index])
		buffer[write_index++] = buffer[read_index++];
	while (write_index < BUFFER_SIZE + 1)
		buffer[write_index++] = '\0';
	return (found_nl);
}

size_t	ft_strllen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	return (len);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*new_line;
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	if (buffer[0] == 0)
		return (0);
	new_line = malloc(ft_strllen(line) + ft_strllen(buffer) + 1);
	if (!new_line)
		return (0);
	while (line && line[index1])
	{
		new_line[index1] = line[index1];
		index1++;
	}
	free (line);
	while (buffer && buffer[index2] && buffer[index2] != '\n')
		new_line[index1++] = buffer[index2++];
	if (buffer[index2] == '\n')
		new_line[index1++] = '\n';
	new_line[index1] = '\0';
	return (new_line);
}
