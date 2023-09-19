/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franciscogomez <franciscogomez@student.42. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:09:30 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/09/19 13:50:40 by franciscogomez   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map.h"
#include "libft/libft.h"
#include "../get_next_line.h"
#include "../graphic_management.h"

int is_ber_file(const char *filename)
{
	const char	*dot;

	dot = ft_strrchr(filename, '.');
	if (dot && ft_strncmp(dot, ".ber", 4) == 0)
		return (1);
	return (0);
}

t_game	*infos(void)
{
	static t_game b;

	return (&b);
}

int verify_map_components(char **map)
{
	int	start_count;
	int	exit_count;
	int	collectible_count;
	int	y;
	int	x;

	start_count = 0;
	exit_count = 0;
	collectible_count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				start_count++;
			else if (map[y][x] == 'E')
				exit_count++;
			else if (map[y][x] == 'C')
				collectible_count++;
			x++;
		}
		y++;
	}
	if (start_count != 1 || exit_count != 1 || collectible_count < 1)
	{
		fprintf(stderr, "Error: Invalid map components\n");
		return (0);
	}
	return (1);
}

int validate_map_chars(const char *line)
{
	while (*line)
	{
		char current_char = *line;
		if (current_char != '0' && current_char != '1' && current_char != 'C' &&
			current_char != 'E' && current_char != 'P' && current_char != '\n')
		{
			fprintf (stderr, "Error: Invalid character '%c' in the map.\n", \
			current_char);
			return (0);
		}
		line++;
	}
	return (1);
}

char	**read_map(const char *filename)
{
	int		fd; 
	char	*line;
	char	**map;
	int		rows;
	int		i;

	if (!is_ber_file(filename))
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL); 
	rows = 0;
	while (get_next_line(fd))
		rows++;
	close(fd); 
	map = (char **)malloc((rows + 1) * sizeof(char *));
	if (!map) 
		return (NULL); 
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(map);
		return (NULL);
	}
	i = 0;
	while ((line = get_next_line(fd)))
	{
		if (!validate_map_chars(line))
		{
			free_map(map, i);
			return (NULL);
		}
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	if (!verify_map_components(map))
	{
		free (map);
		return (NULL);
	}
	if (!is_map_rectangular(map, rows))
	{
		fprintf(stderr, "Error: Map is not rectangular");
		free_map(map, rows);
		return (NULL);
	}
	if (!valid_walls(map, rows))
	{
		fprintf(stderr, "Error: Map doesn't have valid Walls");
		free_map(map, rows);
		return (NULL);
	}
	infos()->height = rows;
	infos()->width = strlen(map[0]) - 1;
	return (map);
}
