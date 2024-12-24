/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:06:51 by diana             #+#    #+#             */
/*   Updated: 2024/12/24 10:24:32 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define	SO_LONG_H
# define	WIN_WIDTH 800
# define	WIN_HEIGHT 600
# define 	WIN_NAME "so_long"


#include "mlx/mlx.h"
#include "structures.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

void	load_images(t_vars *vars);
char	**read_map(char *file);
void	render_map(t_vars *vars);
int		handle_keypress(int keycode, t_vars *vars);
//void	move_player(t_vars *vars, int dx, int dy);

#endif