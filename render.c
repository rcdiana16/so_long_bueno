/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 23:08:54 by diana             #+#    #+#             */
/*   Updated: 2025/01/05 23:34:32 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile_wall(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.wall, \
		x * vars->img_width, y * vars->img_heigth);
}

void	render_tile_background(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.background, \
		x * vars->img_width, y * vars->img_heigth);
}

void	render_tile_other(t_vars *vars, char tile, int x, int y)
{
	if (tile == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.collectible, \
		x * vars->img_width, y * vars->img_heigth);
	}
	else if (tile == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit, x \
		* vars->img_width, y * vars->img_heigth);
	}
	else if (tile == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.player, x \
		* vars->img_width, y * vars->img_heigth);
	}
}

void	render_tile(t_vars *vars, char tile, int x, int y)
{
	if (tile == '1')
		render_tile_wall(vars, x, y);
	else if (tile == '0')
		render_tile_background(vars, x, y);
	else
		render_tile_other(vars, tile, x, y);
}

void	render_row(t_vars *vars, int y)
{
	int	x;

	x = 0;
	while (vars->map[y][x])
	{
		render_tile(vars, vars->map[y][x], x, y);
		x++;
	}
}
