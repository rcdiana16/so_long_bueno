/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:48:30 by diana             #+#    #+#             */
/*   Updated: 2025/01/07 21:30:03 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extentio(char *argv)
{
	char	*ext;

	ext = ft_strchr(argv, '.');
	if (!ext)
	{
		ft_printf("Error\nNot good extention\n");
		exit (1);
	}
	if (ft_strncmp(ext, ".ber", 4) != 0)
	{
		ft_printf("Error\nNot good extention\n");
		exit(1);
	}
	return (0);
}

int	handle_valid_map_error(t_vars *vars)
{
	if (vars->count_e != 1)
	{
		ft_printf("Error\nThere must be exactly one exit\n");
		clean_exit(vars);
		return (0);
	}
	if (vars->count_p != 1)
	{
		ft_printf("Error\nThere must be exactly one player position\n");
		clean_exit(vars);
		return (0);
	}
	if (vars->count_c < 1)
	{
		ft_printf("Error\nThere must be at least one collectible\n");
		clean_exit(vars);
		return (0);
	}
	return (0);
}

void	check_errors(t_vars *vars)
{
	vars->exit_found = 0;
	correct_walls(vars);
	correct_character(vars);
	is_map_solvable(vars);
}

int	get_map_height(t_vars *vars)
{
	int	height;

	height = 0;
	while (vars->map[height])
		height++;
	return (height);
}
