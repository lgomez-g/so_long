/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:34:49 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/08/23 15:35:57 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_MANAGEMENT_H
# define GAME_MANAGEMENT_H

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
	char 	**map;
    
    int     player_x;    // Posición del jugador en el eje X
    int     player_y;    // Posición del jugador en el eje Y
    int     movements;   // Número de movimientos del jugador
	int		collected_objects;   // Collectibles Collected
	int		total_collectibles; // Se calcula al principio
};


static void	move_player(t_game *game, int new_x, int new_y);
int calcular_total_collectibles(char **map);
int handle_key(int keycode, t_game *game);

#endif