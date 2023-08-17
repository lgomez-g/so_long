/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:31:06 by franciscogomez    #+#    #+#             */
/*   Updated: 2023/08/17 16:42:22 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphic_management.h"


void	handle_esc(t_game *game)
{
	(void) game;
	printf("handle_esc\n");
	exit(0);
}

void	handle_esc_key(int keycode, t_game *game)
{
	printf("handle_esc_key: %i\n", keycode);
    if (keycode == 65307)  // 27 es el código de ESC
    {
        mlx_destroy_window(game->mlx, game->windows);
        exit(0);
    }
}
