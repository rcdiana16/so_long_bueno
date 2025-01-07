/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:12:52 by diana             #+#    #+#             */
/*   Updated: 2025/01/07 16:44:47 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_arguments(int argc)
{
	if (argc != 2)
	{
		ft_printf("Error in the number of arguments\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (handle_arguments(argc))
		return (1);
	ft_bzero(&vars, sizeof(t_vars));
	check_extentio(argv[1]);
	vars.map = read_map(argv[1]);
	check_map(&vars);
	handle_valid_map_error(&vars);
	find_p_y_start(&vars);
	check_errors(&vars);
	vars.counter = 0;
	vars.mlx = mlx_init();
	load_images(&vars);
	vars.map_width = ft_strlen(vars.map[0]) * vars.img_width;
	vars.map_height = get_map_height(&vars) * vars.img_heigth;
	vars.win = mlx_new_window(vars.mlx, vars.map_width, vars.map_height, \
	"so_long");
	render_map(&vars);
	mlx_key_hook(vars.win, handle_keypress, &vars);
	mlx_hook(vars.win, 17, 0L, clean_exit, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
