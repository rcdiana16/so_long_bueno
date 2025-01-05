/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:27:09 by diana             #+#    #+#             */
/*   Updated: 2025/01/05 21:33:49 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_vars vars)
{
	int	i;

	i = 0;
	while (i < vars.rows)
	{
		free(vars.map[i]);
		i++;
	}
	free(vars.map);
}

int	clean_exit(t_vars *vars)
{
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
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	free_map(*vars);
	exit(0);
}
