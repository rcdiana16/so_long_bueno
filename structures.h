/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:47:33 by diana             #+#    #+#             */
/*   Updated: 2025/01/03 19:09:36 by diana            ###   ########.fr       */
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
	int		fd;

	void	*mlx;// lo mismo que *mlxpointer?
	void	*win;//lo mismo que *winpointer?
	int		counter;
	t_images img;
	char	**map;
	int		map_width;//numero de columnas
	int		map_height;//numero de filas
	int		img_width;
	int		img_heigth;
	int		player_x;
	int		player_y;
	int		moves;//util?
	//int		collectables;
	int		rows;//si la utilizo
	int		exitcount;
	int		count_e;
	int		count_c;
	int		count_p;
	int		exit_found;
}	t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif