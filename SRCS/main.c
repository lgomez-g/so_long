/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:42:08 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/08/22 12:34:46 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphic_management.h"



int	ft_render(t_game *a)
{
	int y;
	int x;

	y = 0;
	while(a->map[y])
	{
		x = 0;
		while(a->map[y][x])
		{
			if (a->map[y][x] == '1')
				mlx_put_image_to_window(a->mlx, a->windows, a->img_wall, x  * 32, y * 32);
			else if (a->map[y][x] == '0')
				mlx_put_image_to_window(a->mlx, a->windows, a->img_background, x  * 32, y * 32);
			else if (a->map[y][x] == 'C')
				mlx_put_image_to_window(a->mlx, a->windows, a->img_collectible, x  * 32, y * 32);
			else if (a->map[y][x] == 'P')
				mlx_put_image_to_window(a->mlx, a->windows, a->img_background, x  * 32, y * 32);
			else if (a->map[y][x] == 'E')
				mlx_put_image_to_window(a->mlx, a->windows, a->img_exit, x  * 32, y * 32);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(a->mlx, a->windows, a->img_player, a->player_x  * 32, a->player_y * 32);
	//printf("a\n");
	return (0);
}




char *tes(char *str)
{
	char *a  = malloc(15);
	for (int x = 0; x < 10; x++)
	{
		a[x] = str[x];
		a[x + 1 ] = 0;
	}
	return (a);
}


int	main(void)
{
	static t_game	a;

	a.player_x = 2; // Coordenada X
    a.player_y = 2; // Coordenada Y
	a.collected_objects = 0;

	a.map = malloc(sizeof(char *) * 10);

	a.map[0] = tes("1111111111");
	a.map[1] = tes("10C00000E1");
	a.map[2] = tes("100P000001");
	a.map[3] = tes("100000C001");
	a.map[4] = tes("1111111111");
	a.map[5] = NULL;

	a.mlx = mlx_init();
	a.windows = mlx_new_window(a.mlx, 320, 160, "Game");
	a.total_collectibles = calcular_total_collectibles(a.map);
	a.img_wall = mlx_xpm_file_to_image(a.mlx, "images/wall.xpm", &a.width, &a.height);
	a.img_background =  mlx_xpm_file_to_image(a.mlx, "images/background.xpm", &a.width, &a.height);
	a.img_collectible =  mlx_xpm_file_to_image(a.mlx, "images/collectible.xpm", &a.width, &a.height);
	a.img_player =  mlx_xpm_file_to_image(a.mlx, "images/player.xpm", &a.width, &a.height);
	a.img_exit =  mlx_xpm_file_to_image(a.mlx, "images/exit.xpm", &a.width, &a.height);
	mlx_hook(a.windows, 17, 0, (void *) handle_x, &a); // Window Closing
	mlx_key_hook(a.windows, handle_key, &a);// Key handling
	mlx_loop_hook(a.mlx, ft_render, &a); // Render game images
	mlx_loop(a.mlx);
}
