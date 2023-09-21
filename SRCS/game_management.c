/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:34:53 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/09/21 19:59:48 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'C')
		{
			game->map[new_y][new_x] = '0';
			game->collected_objects--;
		}
		game->player_x = new_x;
		game->player_y = new_y;
		game->movements++;
		if (!game->collected_objects
			&& game->map[game->player_y][game->player_x] == 'E')
			quit_f(game);
		ft_printf("Movimientos realizados: %d\n", game->movements);
	}
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		quit_f(game);
	if (keycode == 'w' || keycode == 65362)
		move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == 's' || keycode == 65364)
		move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == 'a' || keycode == 65361)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == 'd' || keycode == 65363)
		move_player(game, game->player_x + 1, game->player_y);
	ft_render(game);
	return (0);
}
