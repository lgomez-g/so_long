/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franciscogomez <franciscogomez@student.42. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:25:26 by franciscogomez    #+#    #+#             */
/*   Updated: 2023/08/16 18:25:29 by franciscogomez   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>

void handle_smooth_window_management(void *mlx);
void handle_esc_key(int keycode, void *param);
int handle_close_window(void *param);

#endif

