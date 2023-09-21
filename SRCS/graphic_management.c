/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:21:32 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/09/21 19:36:52 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


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

int	quit_f(t_game *game)
{
	if(!game->collected_objects
			&& game->map[game->player_y][game->player_x] == 'E')
		ft_printf("\033[1;32mYou Win!\033[0m\n");
	else
		ft_printf("\033[1;34mYou Out!\033[0m\n");
	mlx_destroy_image(game->mlx, game->img_background);
	mlx_destroy_image(game->mlx, game->img_collectible);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_window(game->mlx, game->windows);
	mlx_destroy_display(game->mlx);
	// free_map(game->map, game->height);
	// free_map(game->temp_map, game->height);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}
