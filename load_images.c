/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:35:23 by diana             #+#    #+#             */
/*   Updated: 2024/12/30 18:10:40 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "structures.h"

void	load_images(t_vars *vars)
{
	vars->img.background = mlx_xpm_file_to_image(vars->mlx, \
	"images/background.xpm", &vars->img_width, &vars->img_heigth);

	vars->img.wall = mlx_xpm_file_to_image(vars->mlx, \
	"images/wall.xpm", &vars->img_width, &vars->img_heigth);

	vars->img.collectible= mlx_xpm_file_to_image(vars->mlx, \
	"images/collectible.xpm", &vars->img_width, &vars->img_heigth);

	vars->img.exit = mlx_xpm_file_to_image(vars->mlx, \
	"images/exit.xpm", &vars->img_width, &vars->img_heigth);

	vars->img.player = mlx_xpm_file_to_image(vars->mlx, \
	"images/player.xpm", &vars->img_width, &vars->img_heigth);
}
