/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franciscogomez <franciscogomez@student.42. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:14:48 by franciscogomez    #+#    #+#             */
/*   Updated: 2023/08/16 22:15:07 by franciscogomez   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "map_reader.h"
#include <stdio.h>
#include <stdlib.h>

t_map *parse_map_from_file(const char *filename)
{
    // Use read_line function to read lines from the file
    // Validate and parse the map based on the lines read
    // Return the parsed t_map structure
}

int validate_map(t_map *map)
{
    // Validate the map layout based on the rules you provided
    // Return 1 for a valid map, 0 for an invalid map
}