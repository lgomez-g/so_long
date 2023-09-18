/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:21:32 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/09/18 18:37:49 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphic_management.h"

void	handle_x(t_game *game)	// Para salir con la cruz
{
	(void) game;
	exit(0);
}

int	ft_render(t_game *a)
{
	int	y;
	int	x;

	y = 0;
	while (a->map[y])
	{
		x = 0;
		while (a->map[y][x])
		{
			if (a->map[y][x] == '1')
				mlx_put_image_to_window(a->mlx, a->windows, \
					a->img_wall, x * 32, y * 32);
			else if (a->map[y][x] == '0')
				mlx_put_image_to_window(a->mlx, a->windows, \
					a->img_background, x  * 32, y * 32);
			else if (a->map[y][x] == 'C')
				mlx_put_image_to_window(a->mlx, a->windows, \
					a->img_collectible, x  * 32, y * 32);
			else if (a->map[y][x] == 'P')
				mlx_put_image_to_window(a->mlx, a->windows, \
					a->img_background, x  * 32, y * 32);
			else if (a->map[y][x] == 'E')
				mlx_put_image_to_window(a->mlx, a->windows, \
					a->img_exit, x  * 32, y * 32);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window (a->mlx, a->windows, a->img_player, \
	a->player_x * 32, a->player_y * 32);
	return (0);
}
