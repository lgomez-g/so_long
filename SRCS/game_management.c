/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franciscogomez <franciscogomez@student.42. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:34:53 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/09/19 13:51:03 by franciscogomez   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_management.h"
#include "../graphic_management.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'C')
		{
			game->map[new_y][new_x] = '0';
			game->collected_objects++;
		}
		game->player_x = new_x;
		game->player_y = new_y;
		game->movements++;
		if (game->collected_objects == game->total_collectibles
			&& game->map[game->player_y][game->player_x] == 'E')
		{
			printf("¡You Win!\n");
			mlx_destroy_window(game->mlx, game->windows);
			exit(0);
		}
	}
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->windows);
		exit (0);
	}
	if (keycode == 119)
		move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == 115)
		move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == 97) 
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == 100) 
		move_player(game, game->player_x + 1, game->player_y);
	mlx_clear_window(game->mlx, game->windows);
	printf("Movimientos realizados: %d\n\033c", game->movements);
	return (0);
}

int	calcular_total_collectibles(char **map)
{
	int	total_collectibles;
	int	y;
	int	x;

	y = 0;
	x = 0;
	total_collectibles = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				total_collectibles++;
			x++; 
		}
		y++;
	}
	return (total_collectibles); 
}
