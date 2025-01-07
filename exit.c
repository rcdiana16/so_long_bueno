/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:43:56 by diana             #+#    #+#             */
/*   Updated: 2025/01/07 16:43:59 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	clean_exit(t_vars *vars)
{
	free_map(vars->map);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->img.background)
		mlx_destroy_image(vars->mlx, vars->img.background);
	if (vars->img.wall)
		mlx_destroy_image(vars->mlx, vars->img.wall);
	if (vars->img.collectible)
		mlx_destroy_image(vars->mlx, vars->img.collectible);
	if (vars->img.player)
		mlx_destroy_image(vars->mlx, vars->img.player);
	if (vars->img.exit)
		mlx_destroy_image(vars->mlx, vars->img.exit);
	free(vars->mlx);
	exit(0);
}
