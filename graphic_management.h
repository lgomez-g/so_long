/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_management.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:25:26 by franciscogomez    #+#    #+#             */
/*   Updated: 2023/09/14 16:48:20 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_MANAGEMENT_H
# define GRAPHIC_MANAGEMENT_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>

typedef struct s_game	t_game;

struct					s_game
{
	void				*mlx;
	void				*windows;
	void				*img_wall;
	void				*img_background;
	void				*img_collectible;
	void				*img_player;
	void				*img_exit;
	int					width;
	int					height;
	char				**map;
	char				**temp_map;
	int					player_x;
	int					player_y;
	int					movements;
	int					collected_objects;
	int					total_collectibles;
	bool				valid_path;
};

void					handle_x(t_game *game);
int						ft_render(t_game *a);
t_game					*infos(void);

#endif