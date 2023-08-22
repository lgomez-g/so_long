/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:31:06 by franciscogomez    #+#    #+#             */
/*   Updated: 2023/08/22 13:28:05 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphic_management.h"


void	handle_x(t_game *game)	// Para salir con la cruz
{
	(void) game;
	exit(0);
}

static void	move_player(t_game *game, int new_x, int new_y)
{

	if ( game->map[new_y][new_x] != '1')
	{
		if ( game->map[new_y][new_x] == 'C')
		{
			game->map[new_y][new_x] = '0';
			printf("C\n");
			game->collected_objects++;
		}
		game->player_x = new_x;
		game->player_y = new_y;
		game->movements++;
		if (game->collected_objects == game->total_collectibles && game->map[game->player_y][game->player_x] == 'E')
		{
                    printf("¡You Win!\n");
                    mlx_destroy_window(game->mlx, game->windows);
                    exit(0);
        }
	}
}

int handle_key(int keycode, t_game *game)
{
	if (keycode == 65307) // Código de la tecla Esc
	{
		mlx_destroy_window(game->mlx, game->windows);
	 	exit(0);
 	}
	if (keycode == 119) // Tecla W (arriba)
		move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == 115) // Tecla S (abajo)
		move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == 97) // Tecla A (izquierda)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == 100) // Tecla D (derecha)
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}

int calcular_total_collectibles(char **map)
{
	int total_collectibles = 0; 

	int y = 0;
	while(map[y]) // Cambia "a->map[y]" a "map[y]"
	{
		int x = 0;
		while(map[y][x])
		{
			if (map[y][x] == 'C')
				total_collectibles++;
			
			x++; 
		}
		y++;
	}

	return total_collectibles; 
}
