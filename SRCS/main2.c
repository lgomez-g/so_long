/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franciscogomez <franciscogomez@student.42. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:21:48 by franciscogomez    #+#    #+#             */
/*   Updated: 2023/08/16 22:22:46 by franciscogomez   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "so_long.h"
#include "map.h"

int main(int argc, char **argv)
{
    // Check if the correct number of command-line arguments is provided
    if (argc != 2)
    {
        printf("Usage: %s <map.ber>\n", argv[0]);
        return 1;
    }

    // Parse the map from the specified .ber file
    t_map *game_map = parse_map_from_file(argv[1]);
    if (!game_map)
    {
        printf("Error: Failed to parse the map.\n");
        return 1;
    }

    // Validate the parsed map
    if (!validate_map(game_map))
    {
        printf("Error: Invalid map.\n");
        free_map(game_map);
        return 1;
    }

    // Initialize your game using the parsed and validated map
    // ... Your game initialization code here ...

    // Free memory used for the map
    free_map(game_map);

    return 0;
}