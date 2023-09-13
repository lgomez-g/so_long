/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:16:50 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/09/13 17:42:20 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map.h"
#include "libft/libft.h"
#include "../get_next_line.h"
#include "../graphic_management.h"

bool	is_map_rectangular(char **map, int rows)
{
	size_t	first_row_length;
	size_t	current_row_length;
	int	i;

	i = 0;
	if (rows == 0)
		return (false);
	first_row_length = strlen(map[0]) - (map[0][strlen(map[0]) - 1] == '\n');
	while (i < rows)
	{
		current_row_length = strlen(map[i]) - 
			(map[i][first_row_length] == '\n');
		if (current_row_length != first_row_length)
			return (false);
		i++;
	}
	return (true);
}

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
		free(map[i++]);
	free(map);
}

bool	valid_walls(char **map, int rows)
{
	int	i;
	int	j;
	int	last_char;

	i = 0;
	last_char = strlen(map[0]) - (map[0][strlen(map[0]) - 1] == '\n') - 1;
	while (i < rows)
	{
		j = 0;
		if (!i || !(i < rows - 1))
			while (map[i][j] && map[i][j] != '\n')
				if (map[i][j++] != '1')
					return (false);
		if (map[i][0] != '1' || map[i][last_char] != '1')
			return (false);
		i++;
	}
	return (true);
}
