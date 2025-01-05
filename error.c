/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:48:30 by diana             #+#    #+#             */
/*   Updated: 2025/01/05 23:07:53 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		ft_printf("\nThis map is missing the walls\n");
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
		ft_printf("\nError invalid character!%c\n", vars->map[height][width]);
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
