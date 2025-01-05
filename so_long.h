/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:06:51 by diana             #+#    #+#             */
/*   Updated: 2025/01/03 19:24:44 by diana            ###   ########.fr       */
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
#include <stdlib.h> // malloc, free, exit
#include <stdio.h> //perror
#include <fcntl.h> //open
#include <unistd.h> // close, read, write
#include <string.h> //strerror
#include <stddef.h> //lo dejo?

void	load_images(t_vars *vars);
char	**read_map(char *file);
void	render_tile_wall(t_vars *vars, int x, int y);
void	render_tile_background(t_vars *vars, int x, int y);
void	render_tile_other(t_vars *vars, char tile, int x, int y);
void	render_tile(t_vars *vars, char tile, int x, int y);
void	render_row(t_vars *vars, int y);
void	render_map(t_vars *vars);
int		handle_keypress(int keycode, t_vars *vars);
int		handle_valid_map_error(t_vars *vars);//es necesario? esta en main.c
int		get_map_height(t_vars *vars);//es necesario? esta en main.c
void	correct_character(t_vars *vars);
void	check_errors(t_vars *vars);
int		find_p_y_start(t_vars *map);
int		clean_exit(t_vars *vars);
void	free_map(t_vars vars);



#endif