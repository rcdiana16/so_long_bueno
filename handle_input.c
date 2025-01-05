/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:31:49 by diana             #+#    #+#             */
/*   Updated: 2025/01/05 23:24:40 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_up(t_vars *vars, int x, int y)
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

int	handle_down(t_vars *vars, int x, int y)
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

int	handle_left(t_vars *vars, int x, int y)
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

int	handle_right(t_vars *vars, int x, int y)
{
	if (vars->map[y][x + 1] != '1' && vars->map[y][x + 1] != 'E')
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
