/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:48:30 by diana             #+#    #+#             */
/*   Updated: 2025/01/03 10:17:58 by diana            ###   ########.fr       */
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
	mlx_destroy_image(vars->mlx, vars->img.background);
	vars->img.background = NULL;
	mlx_destroy_image(vars->mlx, vars->img.wall);
	vars->img.wall = NULL;
	mlx_destroy_image(vars->mlx, vars->img.collectible);
	vars->img.collectible = NULL;
	mlx_destroy_image(vars->mlx, vars->img.player);
	vars->img.player = NULL;
	mlx_destroy_image(vars->mlx, vars->img.exit);
	vars->img.exit = NULL;
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	free_map(*vars);
	exit(0);
}

static int	wall_hori(t_vars *vars)
{
	int	x;

	x = 0;
	while (vars->map[0][x])
	{
		if (vars->map[0][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (vars->map[vars->map_height -1][x])
	{
		if (vars->map[vars->map_height -1][x] != '1')
		{
			ft_printf("last ine not full 1\n");
			return (1);
		}
		x++;
	}
	return (0);
}

int	wall_vert(t_vars *vars)
{
	int	height;

	height = 0;
	while (vars->map[height])
	{
		if (vars->map[height][0] != '1')
		{
			ft_printf("1 column not full 1\n");
			return (1);
		}
		if (vars->map[height][vars->map_width -1] != '1')
		{
			ft_printf("last column not full 1\n");
			return (1);
		}
		height++;
	}
	return (0);
}

void	correct_walls(t_vars *vars)
{
	int	wallsvertical;
	int	wallshorizontal;

	wallsvertical = wall_vert(vars);
	wallshorizontal = wall_hori(vars);
	if (wallshorizontal == 1 || wallsvertical == 1)
	{
		printf("\nThis map is missing the walls\n");
		clean_exit(vars);
	}
}

static void	count_checker(t_vars *vars, int height, int width)
{
	if (vars->map[height][width] != '1' && \
			vars->map[height][width] != '0' && \
			vars->map[height][width] != 'P' && \
			vars->map[height][width] != 'E' && \
			vars->map[height][width] != 'C')
	{
		printf("\nError invalid character!%c\n", vars->map[height][width]);
		clean_exit(vars);
	}
}

void	correct_character(t_vars *vars)
{
	int	height;
	int	width;

	height = 0;
	while (height < vars->map_height -1)
	{
		width = 0;
		while (width <= vars->map_width - 1)
		{
			count_checker(vars, height, width);
			width++;
		}
		height++;
	}
}

void	check_errors(t_vars *vars)
{
	correct_walls(vars);
	correct_character(vars);
}
