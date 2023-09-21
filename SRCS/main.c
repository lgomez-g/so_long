/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:19:16 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/09/21 15:57:44 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphic_management.h"
#include "../game_management.h"
#include "../map.h"
#include "libft/libft.h"

void	find_p(t_game	*a)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (a->map[y])
	{
		x = 0;
		while (a->map[y][x])
		{
			if (a->map[y][x] == 'P')
			{
				// printf("\n x : %d | y : %d \n", x, y);
				a->player_x = x;
				a->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	main(void)
{
	static t_game	a;
	char			**map;

	a.collected_objects = 0;
	a.map = read_map("maps/map_level_1.ber");
	if (!a.map)
	{
		perror("Error To Load Map");
		return (1);
	}
	map = duplicate_map(a.map, infos()->height, infos()->width);
	find_p(&a);
	a.valid_path = false;
	flood_fill(&a, a.player_x, a.player_y);
	if (a.valid_path == false)
	{
		perror("Error: No valid path in the map.\n");
		free_map(map, infos()->height);
		// free_map(a.map, infos()->height);
		exit(1);
	}
	a.map = map;
	if (!verify_map_characters(a.map))
	{
		free_map(a.map, infos()->height);
		return (1);
	}
	a.mlx = mlx_init();
	a.windows = mlx_new_window(a.mlx, infos()->width * 32, \
	infos()->height * 32, "Game");
	a.total_collectibles = calcular_total_collectibles(a.map);
	a.img_wall = mlx_xpm_file_to_image(a.mlx, "images/wall.xpm", \
	&a.width, &a.height);
	a.img_background = mlx_xpm_file_to_image(a.mlx, "images/background.xpm", \
	&a.width, &a.height);
	a.img_collectible = mlx_xpm_file_to_image(a.mlx, "images/collectible.xpm", \
	&a.width, &a.height);
	a.img_player = mlx_xpm_file_to_image(a.mlx, "images/player.xpm", \
	&a.width, &a.height);
	a.img_exit = mlx_xpm_file_to_image(a.mlx, "images/exit.xpm", \
	&a.width, &a.height);
	mlx_hook(a.windows, 17, 0, (void *) handle_x, &a);
	mlx_key_hook(a.windows, handle_key, &a);
	// mlx_loop_hook(a.mlx, ft_render, &a);
	mlx_loop(a.mlx);
}