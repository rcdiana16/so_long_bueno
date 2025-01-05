/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:18:29 by diana             #+#    #+#             */
/*   Updated: 2025/01/05 23:23:01 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyboard_ad(t_vars *vars, int keycode)
{
	int	x;
	int	y;

	x = vars->player_x;
	y = vars->player_y;
	if (keycode == 0)
	{
		return (handle_left(vars, x, y));
	}
	else if (keycode == 2)
	{
		return (handle_right(vars, x, y));
	}
	return (1);
}

int	keyboard_ws(t_vars *vars, int keycode)
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
