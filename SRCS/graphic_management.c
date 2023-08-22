/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:31:06 by franciscogomez    #+#    #+#             */
/*   Updated: 2023/08/22 09:49:33 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphic_management.h"


void	handle_x(t_game *game)
{
	(void) game;
	printf("handle_x\n");
	exit(0);
}

void	handle_key(int keycode, t_game *game)
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
        	// Verifica si la celda contiene un objeto coleccionable
        	if (game->map[game->player_y - 1][game->player_x] == 'C')
       		{
            	game->map[game->player_y - 1][game->player_x] = '0'; // Cambia el objeto coleccionable por un espacio en blanco
            	game->collected_objects++; // Incrementa el contador de objetos recolectados
       		}
        	game->player_y--;
        	game->movements++;
    	}
	}
	else if (keycode == 115) // Tecla S (abajo)
	{
    	if (game->map[game->player_y + 1][game->player_x] != '1')
    	{
        	if (game->map[game->player_y + 1][game->player_x] == 'C')
        	{
            	game->map[game->player_y + 1][game->player_x] = '0'; 
            	game->collected_objects++; 
                
        	}
        	game->player_y++;
        	game->movements++;
    	}
	}
	else if (keycode == 97) // Tecla A (izquierda)
	{
        if (game->map[game->player_y][game->player_x - 1] != '1')
        {
            if (game->map[game->player_y][game->player_x - 1] == 'C')
            {
                game->map[game->player_y][game->player_x - 1] = '0'; 
                game->collected_objects++; 
            }
            game->player_x--;
            game->movements++;
        }
	}
	else if (keycode == 100) // Tecla D (derecha)
	{
        if (game->map[game->player_y][game->player_x + 1] != '1')
        {
            if (game->map[game->player_y][game->player_x + 1] == 'C')
            {
                game->map[game->player_y][game->player_x + 1] = '0'; 
                game->collected_objects++; 
            }
            game->player_x++;
            game->movements++;
		}  
	}
}



