/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:42:08 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/08/14 15:51:11 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

int	main(void)
{
	void *mlx;
	void *windows;
	void *img;
	int width,  height;


	mlx = mlx_init();
	windows = mlx_new_window(mlx, 800, 600, "Game");
	img = mlx_xpm_file_to_image(mlx, "images/a.xpm", &width, &height);
	mlx_put_image_to_window(mlx, windows, img, 0, 0);
	printf("width: %i height: %i\n", width, height);
	(void) windows;
	(void) img;
	mlx_loop(mlx);
}
