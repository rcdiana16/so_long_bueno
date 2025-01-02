/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:31:49 by diana             #+#    #+#             */
/*   Updated: 2025/01/02 18:01:28 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "structures.h"

static int handle_up(t_vars *game, int x, int y);
static int	handle_down(t_vars *game, int x, int y);
static int handle_left(t_vars *game, int x, int y);
static int	handle_right(t_vars *game, int x, int y);
int	handle_keypress(int keycode, t_vars *game);
static int	keyboard_ad(t_vars *game, int movement);
static int	keyboard_ws(t_vars *game, int movement);

static int handle_up(t_vars *game, int x, int y)
{
	if (game->map[y - 1][x] != '1')
	{
		game->map[y - 1][x] = 'P';
		game->map[y][x] = '0';
		game->player_y -= 1;
	}
	render_map(game);
	//printf("steps:%i\n", game->counter);
	//printf("collectables left: %i\n", game->collectables);
	return (0);
}

static int	handle_down(t_vars *game, int x, int y)
{
	if (game->map[y + 1][x] != '1')
	{
		game->map[y + 1][x] = 'P';
		game->map[y][x] = '0';
		game->player_y += 1;
	}
	render_map(game);
	//printf("steps:%i\n", game->counter);
	//printf("collectables left: %i\n", game->collectables);
	return (0);
}

static int handle_left(t_vars *game, int x, int y)
{
	if (game->map[y][x - 1] != '1')
	{
		game->map[y][x - 1] = 'P';
		game->map[y][x] = '0';
		game->player_x -= 1;
	}
	render_map(game);
	//printf("steps:%i\n", game->counter);
	//printf("collectables remaining: %i\n", game->collectables);
	return (0);
}

static int	handle_right(t_vars *game, int x, int y)
{
	if (game->map[y][x + 1] != '1')
	{
		game->map[y][x + 1] = 'P';
		game->map[y][x] = '0';

		game->player_x += 1;
	}
	render_map(game);
	//printf("steps:%i\n", game->counter);
	//printf("collectables remaining: %i\n", game->collectables);
	return (0);
}

static int	keyboard_ad(t_vars *game, int keycode)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (keycode == 0)
	{
		ft_printf("keycode value: %d\n", keycode);
		ft_printf("player_x = %d\n player_y = %d\n", x, y);
		return (handle_left(game, x, y ));
	}
	else if (keycode == 2)
	{
		ft_printf("keycode value: %d\n", keycode);
		ft_printf("player_x = %d\n player_y = %d\n", x, y);
		return (handle_right(game, x, y));
	}
	return (1);
}

static int	keyboard_ws(t_vars *game, int keycode)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (keycode == 13)
	{
		return (handle_up(game, x, y));
	}
	else if (keycode == 1)
	{
		return (handle_down(game, x, y));
	}
	return (1);
}

int	handle_keypress(int keycode, t_vars *game)
{
	if (keycode == 53)
		mlx_destroy_window(game->mlx, game->win);
	if (keycode == 13)
		keyboard_ws(game, keycode);
	else if (keycode == 1)
		keyboard_ws(game, keycode);
	else if (keycode == 0)
		keyboard_ad(game, keycode);
	else if (keycode == 2)
		keyboard_ad(game, keycode);
	return (1);
}

/*
//Aparece venata de juego y si presiono teclas aparece en 
//la terminal que letra utilice
int	handle_keypress(int keycode) //t_vars *vars)
{
	if (keycode == 53)
		exit(1);
		//mlx_destroy_window(vars->mlx, vars->win);
	else if (keycode == 13)
		printf("Tecla W presionada: mover arriba\n");
	else if (keycode == 0)
		printf("Tecla A presionada: mover izquierda\n");
	else if (keycode == 1)
		printf("Tecla S presionada: mover abajo\n");
	else if (keycode == 2)
		printf("Tecla D presionada: mover derecha\n");
	return (0);
}
*/

/*
//Esto es algo que al inicio chatgpt me dio pero no se si usar 
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