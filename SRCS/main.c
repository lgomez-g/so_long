/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:19:16 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/09/21 20:03:26 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_p(t_game	*game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	game_init(t_game	*game)
{
	game->map = game->temp_map;
	if (!verify_map_characters(game->temp_map))
	{
		free_map(game->map, game->height);
		free_map(game->temp_map, game->height);
		exit (1);
	}
	game->mlx = mlx_init();
	game->windows = mlx_new_window(game->mlx, game->width * 32, \
	game->height * 32, "so_long");
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", \
	&game->width, &game->height);
	game->img_background = mlx_xpm_file_to_image(game->mlx, \
	"images/background.xpm", \
	&game->width, &game->height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, \
	"images/collectible.xpm", \
	&game->width, &game->height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "images/player.xpm", \
	&game->width, &game->height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm", \
	&game->width, &game->height);
}

// int	main(int argc, char **argv)
int	main(void)
{
	static t_game	game;

	// game.collected_objects = 0;
	// if (argc != 2)
	// {
	// 	perror("Wrong N of arguments");
	// 	return (1);
	// }
	// read_map(&game, argv[1]);
	read_map(&game, "maps/map1.ber");
	if (!game.map)
	{
		perror("Error To Load Map");
		return (1);
	}
	duplicate_map(&game, game.height, game.width);
	find_p(&game);
	game.valid_path = false;
	flood_fill(&game, game.player_x, game.player_y);
	if (game.valid_path == false)
	{
		perror("Error: No valid path in the map.\n");
		free_map(game.map, game.height);
		free_map(game.temp_map, game.height);
		return (1);
	}
	game_init(&game);
	ft_render(&game);
	mlx_hook(game.windows, 17, 0, quit_f, &game);
	mlx_hook(game.windows, KEY_PRESS, 1L << 0, handle_key, &game);
	mlx_loop(game.mlx);
}
