/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franciscogomez <franciscogomez@student.42. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:26:45 by franciscogomez    #+#    #+#             */
/*   Updated: 2023/08/16 22:30:58 by franciscogomez   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

typedef struct s_map t_map;

struct s_map
{
    int width;
    int height;
    char **layout;
};

int validate_map(t_map *map);
t_map *parse_map_from_file(const char *filename);
void free_map(t_map *map);

#endif