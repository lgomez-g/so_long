/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franciscogomez <franciscogomez@student.42. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:31:06 by franciscogomez    #+#    #+#             */
/*   Updated: 2023/08/16 18:52:59 by franciscogomez   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdlib.h>

/*void handle_smooth_window_management(void *mlx)
{
    void *window2;

    window2 = mlx_new_window(mlx, 800, 600, "Another Window");

    usleep(2000000); // Wait for 2 seconds

    mlx_clear_window(mlx, window2);
    mlx_string_put(mlx, window2, 100, 100, 0xFFFFFF, "Minimized Window");

    mlx_loop(mlx);
}*/

void handle_esc_key(int keycode, void *param)
{
    if (keycode == 27)  // 27 es el código de ESC
    {
        mlx_destroy_window(param, window);
        exit(0);
    }
}

int handle_close_window(void *param)
{
    mlx_destroy_window(param, window);
    exit(0);
    return 0;
}