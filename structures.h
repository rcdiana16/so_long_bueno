/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:47:33 by diana             #+#    #+#             */
/*   Updated: 2025/01/05 21:36:39 by diana            ###   ########.fr       */
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

	void	*mlx;
	void	*win;
	int		counter;
	t_images img;
	char	**map;
	int		map_width;
	int		map_height;
	int		img_width;
	int		img_heigth;
	int		player_x;
	int		player_y;
	int		moves;
	int		rows;
	int		exitcount;
	int		count_e;
	int		count_c;
	int		game_c_count;
	int		count_p;
	int		exit_found;
}	t_vars;

#endif
