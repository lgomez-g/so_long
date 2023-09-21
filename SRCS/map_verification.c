/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:16:50 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/09/21 19:53:40 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

bool verify_map_characters(char **map)
{
    int	y;

	y = 0;
    while (map[y])
    {
        int x;
		
		x = 0;
        while (map[y][x])
        {
            char c = map[y][x];
            if (c != '1' && c != 'P' && c != '0' && c != 'C' \
			&& c != 'E' && c != '\n')
                return false;
            x++;
        }
        y++;
    }
    return (true);
}

void flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->width - 1 || y >= game->height - 1
	|| game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'E')
		game->valid_path = true;
	game->map[y][x] = '1';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

void	duplicate_map(t_game *game, int rows, int cols)
{
	int		i;

	i = 0;
	game->temp_map = malloc((rows + 1) * sizeof(char *));
	if (!game->temp_map)
	{
		perror("Error: Memory allocation failed.\n");
		exit(1);
	}
	while (i < rows)
	{
		game->temp_map[i] = (char *)malloc((cols + 1) * sizeof(char));
		if (!game->temp_map[i])
		{
			perror("Error: Memory allocation failed.\n");
			exit(1);
		}
		strcpy(game->temp_map[i], game->map[i]);
		i++;
	}
	game->temp_map[i] = NULL;
}