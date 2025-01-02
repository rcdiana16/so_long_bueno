/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:48:30 by diana             #+#    #+#             */
/*   Updated: 2025/01/01 15:27:26 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	wall_hori(t_vars *game)
{
	int	x;

	x = 0;
	while (game->map[0][x])
	{
		if (game->map[0][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (game->map[game->map_height -1][x])
	{
		if (game->map[game->map_height -1][x] != '1')
		{
			ft_printf("last ine not full 1\n");
			return (1);
		}
		x++;
	}
	return (0);
}

int	wall_vert(t_vars *game)
{
	int	height;

	height = 0;
	while (game->map[height])
	{
		if (game->map[height][0] != '1')
		{
			ft_printf("1 column not full 1\n");
			return (1);
		}
		if (game->map[height][game->map_width -1] != '1')
		{
			ft_printf("last column not full 1\n");
			return (1);
		}
		height++;
	}
	return (0);
}

void	correct_walls(t_vars *game)
{
	int	wallsvertical;
	int	wallshorizontal;

	wallsvertical = wall_vert(game);
	wallshorizontal = wall_hori(game);
	if (wallshorizontal == 1 || wallsvertical == 1)
	{
		printf("\nThis map is missing the walls\n");
		exit(1);
	}
}

static void	count_checker(t_vars *game, int height, int width)
{
	if (game->map[height][width] != '1' && \
			game->map[height][width] != '0' && \
			game->map[height][width] != 'P' && \
			game->map[height][width] != 'E' && \
			game->map[height][width] != 'C')
	{
		printf("\nError invalid character!%c\n", game->map[height][width]);
		exit(1);
	}
}

void	correct_character(t_vars *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->map_height -1)
	{
		width = 0;
		while (width <= game->map_width - 1)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
}

void	check_errors(t_vars *game)
{
	correct_walls(game);
	correct_character(game);
}
