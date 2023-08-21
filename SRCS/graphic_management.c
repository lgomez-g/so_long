/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franciscogomez <franciscogomez@student.42. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:31:06 by franciscogomez    #+#    #+#             */
/*   Updated: 2023/08/21 14:13:24 by franciscogomez   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphic_management.h"


void	handle_x(t_game *game)
{
	(void) game;
	printf("handle_x\n");
	exit(0);
}

void handle_key(int keycode, t_game *game)
{
    if (keycode == 65307) // Código de la tecla Esc
    {
        mlx_destroy_window(game->mlx, game->windows);
        exit(0);
    }
    else if (keycode == 119) // Tecla W (arriba)
    {
        if (game->map[game->player_y - 1][game->player_x] != '1')
        {
            game->player_y--;
            game->movements++;
            printf("Movimientos: %d\n", game->movements); // Muestra el número de movimientos
        }
    }
    else if (keycode == 115) // Tecla S (abajo)
    {
        if (game->map[game->player_y + 1][game->player_x] != '1')
        {
            game->player_y++;
            game->movements++;
            
            printf("Movimientos: %d\n", game->movements); // Muestra el número de movimientos
        }
    }
    else if (keycode == 97) // Tecla A (izquierda)
    {
        if (game->map[game->player_y][game->player_x - 1] != '1')
        {
            game->player_x--;
            game->movements++;
            
            printf("Movimientos: %d\n", game->movements); // Muestra el número de movimientos
        }
    }
    else if (keycode == 100) // Tecla D (derecha)
    {
        if (game->map[game->player_y][game->player_x + 1] != '1')
        {
            game->player_x++;
            game->movements++;
            
            printf("Movimientos: %d\n", game->movements); // Muestra el número de movimientos
        }
    }
}



