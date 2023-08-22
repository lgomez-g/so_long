/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_management.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:25:26 by franciscogomez    #+#    #+#             */
/*   Updated: 2023/08/22 08:57:25 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_MANAGEMENT_H
# define GRAPHIC_MANAGEMENT_H

#include <stdlib.h>
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
	void	*img_player;
	void	*img_exit;
	int 	width;
	int		height;
	char 	*map[6];
    
    int     player_x;    // Posición del jugador en el eje X
    int     player_y;    // Posición del jugador en el eje Y
    int     movements;   // Número de movimientos del jugador
	int		collected_objects; // Collectibles Collected
};



void	handle_x(t_game *game);

void handle_key(int keycode, t_game *game);

#endif