/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:35:23 by diana             #+#    #+#             */
/*   Updated: 2024/12/21 13:30:18 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "structures.h"

void	load_images(t_vars *vars)
{
	vars->img.background = mlx_xpm_file_to_image(vars->mlx, \
	"images/background.xpm", &vars->img_width, &vars->img_heigth);
	if (!vars->img.background)
		printf("Failed to load background image.");

	vars->img.wall = mlx_xpm_file_to_image(vars->mlx, \
	"images/wall.xpm", &vars->img_width, &vars->img_heigth);
	if (!vars->img.wall)
		printf("Failed to load wall image.");

	vars->img.collectible= mlx_xpm_file_to_image(vars->mlx, \
	"images/collectible.xpm", &vars->img_width, &vars->img_heigth);
	//if (!vars->img.collectible)
		//exit_error("Failed to load collectible image.");

	vars->img.exit = mlx_xpm_file_to_image(vars->mlx, \
	"images/exit.xpm", &vars->img_width, &vars->img_heigth);
	//if (!vars->img.exit)
		//exit_error("Failed to load exit image.");

	vars->img.player = mlx_xpm_file_to_image(vars->mlx, \
	"images/player.xpm", &vars->img_width, &vars->img_heigth);
	//if (!vars->img.player)
		//exit_error("Failed to load player image.");
}
