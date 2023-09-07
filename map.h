/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:32:44 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/08/25 21:17:32 by lgomez-g         ###   ########.fr       */
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

#endif