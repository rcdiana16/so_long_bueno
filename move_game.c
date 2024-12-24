/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:31:49 by diana             #+#    #+#             */
/*   Updated: 2024/12/24 10:25:47 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "structures.h"

int	handle_keypress(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	else if (keycode == 13)
		//move_player(vars, 0, -1);
		printf("Tecla W presionada: mover arriba\n");
	else if (keycode == 0)
		//move_player(vars, -1, 0);
		printf("Tecla A presionada: mover izquierda\n");
	else if (keycode == 1)
		//move_player(vars, 0, 1);
		printf("Tecla S presionada: mover abajo\n");
	else if (keycode == 2)
		//move_player(vars, 1, 0);
		printf("Tecla D presionada: mover derecha\n");
	return (0);
}

/*
void	move_player(t_vars *vars, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = vars->player_x + dx;
	new_y = vars->player_y + dy;
	if (vars->map[new_y][new_x] != '1')
	{
		vars->player_x = new_x;
		vars->player_y = new_y;
		printf("Player moved to (%d, %d)\n", vars->player_x, vars->player_y);
	}
	else
	{
		printf("Cannot move to (%d, %d): Blocked\n", new_x, new_y);
	}
}
*/