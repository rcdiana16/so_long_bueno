/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:18:29 by diana             #+#    #+#             */
/*   Updated: 2025/01/02 18:04:37 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "structures.h"
/*
int	correct_move(t_vars *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		printf("\nYou have won, Congratulations!\n");
		exit(1);
	}
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->player_x = x;
		game->player_y = y;
		game->counter++;
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->player_x = x;
		game->player_y = y;
		game->collectables--;
		game->counter++;
	}
	return (1);
}
*/