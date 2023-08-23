/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:19:16 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/08/23 15:37:47 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphic_management.h"
#include "../game_management.h"

int	main(void)
{
	static t_game	a;
	
	//Posicion Inicial
	a.player_x = 2; // Coordenada X
    a.player_y = 2; // Coordenada Y
	
	a.collected_objects = 0;

	a.map = read_map("maps/map_level_1.ber");
	if (!a.map)
	{
		printf(stderr, "Error To Load Map");
		return (1);
	}

	a.mlx = mlx_init();
	a.windows = mlx_new_window(a.mlx, 320, 160, "Game");
	a.total_collectibles = calcular_total_collectibles(a.map);
	a.img_wall = mlx_xpm_file_to_image(a.mlx, "images/wall.xpm", &a.width, &a.height);
	a.img_background =  mlx_xpm_file_to_image(a.mlx, "images/background.xpm", &a.width, &a.height);
	a.img_collectible =  mlx_xpm_file_to_image(a.mlx, "images/collectible.xpm", &a.width, &a.height);
	a.img_player =  mlx_xpm_file_to_image(a.mlx, "images/player.xpm", &a.width, &a.height);
	a.img_exit =  mlx_xpm_file_to_image(a.mlx, "images/exit.xpm", &a.width, &a.height);
	
	//Loops
	mlx_hook(a.windows, 17, 0, (void *) handle_x, &a); // Window Closing
	mlx_key_hook(a.windows, handle_key, &a);// Key handling
	mlx_loop_hook(a.mlx, ft_render, &a); // Render game images
	mlx_loop(a.mlx);
}
