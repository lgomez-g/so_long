/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:34:49 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/08/25 12:53:30 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_MANAGEMENT_H
# define GAME_MANAGEMENT_H

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "graphic_management.h"

void	move_player(t_game *game, int new_x, int new_y);
int calcular_total_collectibles(char **map);
int handle_key(int keycode, t_game *game);

#endif