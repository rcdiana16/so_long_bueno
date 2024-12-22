/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:47:33 by diana             #+#    #+#             */
/*   Updated: 2024/12/21 20:50:27 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	STRUCTURES_H
# define	STRUCTURES_H


typedef struct s_images{
	void	*background;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player;
}	t_images;

typedef struct s_vars{
	void	*mlx;
	void	*win;
	t_images img;
	char	**map;
	int		map_width;//numero de columnas
	int		map_height;//numero de filas
	int		img_width;
	int		img_heigth;
	/*void	*img_background;
	void	*img_wall;
	void	*img_collectible;
	void	*img_exit;
	void	*img_player;*/
	int		player_x;
	int		player_y;
	int		moves;
	int		collectibles;
	int		exit_open;
	int		game_over;
	int		won;
}	t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif