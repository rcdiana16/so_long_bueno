/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:31:49 by diana             #+#    #+#             */
/*   Updated: 2025/01/03 16:51:42 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "structures.h"

/*static int handle_up(t_vars *vars, int x, int y);
static int	handle_down(t_vars *vars, int x, int y);
static int handle_left(t_vars *vars, int x, int y);
static int	handle_right(t_vars *vars, int x, int y);
int	handle_keypress(int keycode, t_vars *vars);
static int	keyboard_ad(t_vars *vars, int keycode);
static int	keyboard_ws(t_vars *vars, int keycode);*/

static int handle_up(t_vars *vars, int x, int y)
{
	if (vars->map[y - 1][x] != '1' && vars->map[y - 1][x] != 'E')
	{
		if (vars->map[y - 1][x] == 'C')
			vars->count_c--;
		vars->map[y - 1][x] = 'P';
		vars->map[y][x] = '0';
		vars->player_y -= 1;
		vars->counter++;
		ft_printf("counter:%d\n", vars->counter);
	}
	if (vars->map[y -1][x] == 'E' && vars->count_c == 0)
	{
		ft_printf("You won\n");
		clean_exit(vars);
	}
	render_map(vars);
	return (0);
}

static int	handle_down(t_vars *vars, int x, int y)
{
	if (vars->map[y + 1][x] != '1' && vars->map[y + 1][x] != 'E')
	{
		if (vars->map[y + 1][x] == 'C')
			vars->count_c--;
		vars->map[y + 1][x] = 'P';
		vars->map[y][x] = '0';
		vars->player_y += 1;
		vars->counter++;
		ft_printf("counter:%d\n", vars->counter);
	}
	if (vars->map[y + 1][x] == 'E' && vars->count_c == 0)
	{
		ft_printf("You won\n");
		clean_exit(vars);
	}
	render_map(vars);
	return (0);
}

static int handle_left(t_vars *vars, int x, int y)
{
	if (vars->map[y][x - 1] != '1' && vars->map[y][x - 1] != 'E')
	{
		if (vars->map[y][x - 1] == 'C')
			vars->count_c--;
		vars->map[y][x - 1] = 'P';
		vars->map[y][x] = '0';
		vars->player_x -= 1;
		vars->counter++;
		ft_printf("counter:%d\n", vars->counter);
	}
	if (vars->map[y][x - 1] == 'E' && vars->count_c == 0)
	{
		ft_printf("You won\n");
		clean_exit(vars);
	}
	render_map(vars);
	return (0);
}

static int	handle_right(t_vars *vars, int x, int y)
{
	if (vars->map[y][x + 1] != '1' && vars->map[y][x+ 1] != 'E')
	{
		if (vars->map[y][x + 1] == 'C')
			vars->count_c--;
		vars->map[y][x + 1] = 'P';
		vars->map[y][x] = '0';

		vars->player_x += 1;
		vars->counter++;
		ft_printf("counter:%d\n", vars->counter);
	}
	if (vars->map[y][x + 1] == 'E' && vars->count_c == 0)
	{
		ft_printf("You won\n");
		clean_exit(vars);
	}
	render_map(vars);
	return (0);
}

static int	keyboard_ad(t_vars *vars, int keycode)
{
	int	x;
	int	y;

	x = vars->player_x;
	y = vars->player_y;
	if (keycode == 0)
	{
		return (handle_left(vars, x, y ));
	}
	else if (keycode == 2)
	{
		return (handle_right(vars, x, y));
	}
	return (1);
}

static int	keyboard_ws(t_vars *vars, int keycode)
{
	int	x;
	int	y;

	x = vars->player_x;
	y = vars->player_y;
	if (keycode == 13)
	{
		return (handle_up(vars, x, y));
	}
	else if (keycode == 1)
	{
		return (handle_down(vars, x, y));
	}
	return (1);
}

int	handle_keypress(int keycode, t_vars *vars)
{
	ft_printf("collectables:%d\n", vars->count_c);
	if (keycode == 53)
		clean_exit(vars);
	if (keycode == 13)
		keyboard_ws(vars, keycode);
	else if (keycode == 1)
		keyboard_ws(vars, keycode);
	else if (keycode == 0)
		keyboard_ad(vars, keycode);
	else if (keycode == 2)
		keyboard_ad(vars, keycode);
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