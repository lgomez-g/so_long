/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:42:08 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/08/15 16:21:26 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <stdio.h>

typedef struct s_game	t_game;

struct s_game
{
	void	*mlx;
	void	*windows;
	void 	*img_wall;
	void	*img_background;
	void	*img_collectible;
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
			x++;
		}
		y++;
	}
	return (0);
}


int	main(void)
{
	static t_game	a;

	a.map[0] = "1111111111";
	a.map[1] = "10000000E1";
	a.map[2] = "100P000001";
	a.map[3] = "10C010C011";
	a.map[4] = "1111111111";


	a.mlx = mlx_init();
	a.windows = mlx_new_window(a.mlx, 320, 160, "Game");
	a.img_wall = mlx_xpm_file_to_image(a.mlx, "images/wall.xpm", &a.width, &a.height);
	a.img_background =  mlx_xpm_file_to_image(a.mlx, "images/background.xpm", &a.width, &a.height);
	a.img_collectible =  mlx_xpm_file_to_image(a.mlx, "images/collectible.xpm", &a.width, &a.height);
	mlx_loop_hook(a.mlx, ft_render, &a);
	mlx_loop(a.mlx);
}
