/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franciscogomez <franciscogomez@student.42. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:42:08 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/08/16 18:57:55 by franciscogomez   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

typedef struct s_game	t_game;

struct s_game
{
	void	*mlx;
	void	*windows;
	void 	*img_wall;
	void	*img_background;
	void	*img_collectible;
	void	*img_player;
	void	*img_exit;
	int 	width;
	int		height;
	char 	*map[6];
};


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
			if (a->map[y][x] == '0')
				mlx_put_image_to_window(a->mlx, a->windows, a->img_background, x  * 32, y * 32);
			if (a->map[y][x] == 'C')
				mlx_put_image_to_window(a->mlx, a->windows, a->img_collectible, x  * 32, y * 32);
			if (a->map[y][x] == 'P')
				mlx_put_image_to_window(a->mlx, a->windows, a->img_background, x  * 32, y * 32);
			if (a->map[y][x] == 'E')
				mlx_put_image_to_window(a->mlx, a->windows, a->img_exit, x  * 32, y * 32);
			x++;
		}
		y++;
	}

	mlx_put_image_to_window(a->mlx, a->windows, a->img_player, 0  * 32, 0 * 32);
	return (0);
}


int	main(void)
{
	static t_game	a;

	a.map[0] = "1111111111";
	a.map[1] = "1000000001";
	a.map[2] = "100P00E001";
	a.map[3] = "10C010C011";
	a.map[4] = "1111111111";

	a.mlx = mlx_init();
	a.windows = mlx_new_window(a.mlx, 320, 160, "Game");
	a.img_wall = mlx_xpm_file_to_image(a.mlx, "images/wall.xpm", &a.width, &a.height);
	a.img_background =  mlx_xpm_file_to_image(a.mlx, "images/background.xpm", &a.width, &a.height);
	a.img_collectible =  mlx_xpm_file_to_image(a.mlx, "images/collectible.xpm", &a.width, &a.height);
	a.img_player =  mlx_xpm_file_to_image(a.mlx, "images/player.xpm", &a.width, &a.height);
	a.img_exit =  mlx_xpm_file_to_image(a.mlx, "images/exit.xpm", &a.width, &a.height);
	
	mlx_key_hook(a.windows, handle_esc_key, &a);  // Set up ESC key handling
	mlx_hook(a.windows, 33, 0, handle_close_window, &a); // Set up window close handling
	
	//mlx_loop_hook(a.mlx, handle_smooth_window_management, &a);  // Set up smooth window management
	mlx_loop_hook(a.mlx, ft_render, &a); 
	mlx_loop(a.mlx);
}
