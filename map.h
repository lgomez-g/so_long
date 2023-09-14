/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:32:44 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/09/14 17:12:25 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include "graphic_management.h"

char	**read_map(const char *filename);
int is_ber_file(const char *filename);
void free_map(char **map, int rows);
bool is_map_rectangular(char **map, int rows);
int verify_map_components(char **map);
void free_map(char **map, int rows);
bool	valid_walls(char **map, int rows);
bool verify_map_characters(char **map);
void flood_fill(t_game *game, int x, int y);
char **duplicate_map(char **map, int rows, int cols);
#endif