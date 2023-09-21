/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:49:39 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/09/21 19:53:33 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define KEY_PRESS 2

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>
# include "SRCS/libft/libft.h"

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

//Graphic M.
void	handle_x(t_game *game);
int		ft_render(t_game *a);
int		quit_f(t_game *game);

//GNL
char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buffer);
size_t	ft_strllen(char *str);
bool	ft_manage_buffer(char *buffer);

//MAP
char	**read_map(t_game *game, char *filename);
int     is_ber_file(const char *filename);
bool	is_map_rectangular(char **map, int rows);
int		verify_map_components(char **map, t_game *game);
void	free_map(char **map, int rows);
bool	valid_walls(char **map, int rows);
bool	verify_map_characters(char **map);
void 	flood_fill(t_game *game, int x, int y);
void	duplicate_map(t_game *game, int rows, int cols);

//Game M.
void	move_player(t_game *game, int new_x, int new_y);
int handle_key(int keycode, t_game *game);


#endif