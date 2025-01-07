/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:06:51 by diana             #+#    #+#             */
/*   Updated: 2025/01/07 16:45:14 by diana            ###   ########.fr       */
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
void	correct_character(t_vars *vars);
void	check_errors(t_vars *vars);
int		find_p_y_start(t_vars *map);
int		clean_exit(t_vars *vars);
void	free_map(char ** map);
int		check_extentio(char *argv);
int		check_map(t_vars *map);
void	count_map_elements(t_vars *map);
int		get_map_height(t_vars *vars);
int		handle_valid_map_error(t_vars *vars);
int 	handle_up(t_vars *vars, int x, int y);
int		handle_down(t_vars *vars, int x, int y);
int 	handle_left(t_vars *vars, int x, int y);
int		handle_right(t_vars *vars, int x, int y);
int		keyboard_ad(t_vars *vars, int keycode);
int		keyboard_ws(t_vars *vars, int keycode);
void	correct_walls(t_vars *vars);
int		is_map_solvable(t_vars *vars);
char	**duplicate_map(t_vars *vars);
int		explore_map(t_vars *vars, char **map, int x_start, int y_start);
void	render_background(t_vars *vars);

#endif
