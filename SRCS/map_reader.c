/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:09:30 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/09/21 20:16:54 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int is_ber_file(const char *filename)
{
	const char	*dot;

	dot = ft_strrchr(filename, '.');
	if (dot && ft_strncmp(dot, ".ber", 4) == 0)
		return (1);
	return (0);
}

int verify_map_components(char **map, t_game *game)
{
	int	start_count;
	int	exit_count;
	int	y;
	int	x;

	start_count = 0;
	exit_count = 0;
	game->collected_objects = 0;
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
				game->collected_objects++;
			x++;
		}
		y++;
	}
	if (start_count != 1 || exit_count != 1 || game->collected_objects < 1)
	{
		perror("Error: Invalid map components");
		return (0);
	}
	return (1);
}
//ok
int validate_map_chars(const char *line)
{
	while (*line)
	{
		char current_char = *line;
		if (current_char != '0' && current_char != '1' && current_char != 'C' &&
			current_char != 'E' && current_char != 'P' && current_char != '\n')
		{
			perror("Error: Invalid character in the map.");
			return (0);
		}
		line++;
	}
	return (1);
}
int	map_v(t_game *game, int fd)
{
	char	*line;
	int		i;
	if (fd == -1)
	{
		free(game->map);
		return (0);
	}
	i = 0;
	while ((line = get_next_line(fd)))
	{
		if (!validate_map_chars(line))
		{
			free_map(game->map, i);
			return (0);
		}
		game->map[i] = line;
		i++;
	}
	game->map[i] = NULL;
	return(1);
}
char	**read_map(t_game *game, char *filename)
{
	int		fd; 

	if (!is_ber_file(filename) || (fd = open(filename, O_RDONLY)) == -1)
		return (NULL); 
	game->height = 0;
	while (get_next_line(fd))
		game->height++;
	close(fd); 
	game->map = (char **)malloc((game->height + 1) * sizeof(char *));
	if (!game->map) 
		return (NULL); 
	fd = open(filename, O_RDONLY);
	if (!map_v(game, fd))
		return(NULL);
	// if (fd == -1)
	// {
	// 	free(game->map);
	// 	return (NULL);
	// }
	// i = 0;
	// while ((line = get_next_line(fd)))
	// {
	// 	if (!validate_map_chars(line))
	// 	{
	// 		free_map(game->map, i);
	// 		return (NULL);
	// 	}
	// 	game->map[i] = line;
	// 	i++;
	// }
	// game->map[i] = NULL;
	close(fd);
    if (!verify_map_components(game->map, game) || !is_map_rectangular(game->map, game->height) || !valid_walls(game->map, game->height))
    {
        free_map(game->map, game->height);
        return (NULL);
    }
	game->width = strlen(game->map[0]) - 1;
	return (game->map);
}
