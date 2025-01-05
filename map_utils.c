/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:09:23 by diana             #+#    #+#             */
/*   Updated: 2025/01/05 23:30:20 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_vars *vars)
{
	int	y;

	y = 0;
	while (vars->map[y])
	{
		render_row(vars, y);
		y++;
	}
}

int	find_p_y_start(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'P')
			{
				vars->player_y = y;
				vars->player_x = x;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	get_map_height(t_vars *vars)
{
	int	height;

	height = 0;
	while (vars->map[height])
		height++;
	return (height);
}

void	count_map_elements(t_vars *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'E')
				map->count_e++;
			else if (map->map[y][x] == 'P')
				map->count_p++;
			else if (map->map[y][x] == 'C')
				map->count_c++;
			x++;
		}
		y++;
	}
}

int	check_map(t_vars *map)
{
	int	y;

	y = 0;
	count_map_elements(map);
	while (map->map[y])
		y++;
	map->map_height = y;
	map->map_width = ft_strlen(map->map[0]);
	map->game_c_count = map->count_c;
	return (0);
}
