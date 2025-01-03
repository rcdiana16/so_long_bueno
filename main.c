/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:12:52 by diana             #+#    #+#             */
/*   Updated: 2025/01/02 22:25:55 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"
#include "structures.h"
#include <stdio.h>
#include <unistd.h>

int	handle_valid_map_error(t_vars *vars)
{
	if (vars->count_e != 1)
	{
		printf("Error\nThere must be exactly one exit\n");
		return (0);
	}
	if (vars->count_p != 1)
	{
		printf("Error\nThere must be exactly one player position\n");
		return (0);
	}
	if (vars->count_c < 1)
	{
		printf("Error\nThere must be at least one collectible\n");
		return (0);
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

int check_map(t_vars *map)
{
	int	x;
	int	y;

	x = 0;
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
	map->map_height = y;
	map->map_width = x;
	return (0);
}

int	check_extentio(char *argv)
{
	char *ext;
	ext = ft_strchr(argv ,'.');
	if (ft_strncmp(ext, ".ber", 4) != 0)
	{
		ft_printf("not good extention\n");
		exit(1);
	}
	return (0);
}
int main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		printf("Error in the number of arguments\n");
		return (1);
	}
	check_extentio(argv[1]);
	vars.map = read_map(argv[1]);
	check_map(&vars);
	if (handle_valid_map_error(&vars) != 1)
		//exit_game(vars);
	check_errors(&vars);
	find_p_y_start(&vars);
	vars.counter = 0;
	vars.mlx = mlx_init();
	load_images(&vars);
	vars.map_width = ft_strlen(vars.map[0]) * vars.img_width;
	vars.map_height = get_map_height(&vars) * vars.img_heigth;
	vars.win = mlx_new_window(vars.mlx,  vars.map_width, vars.map_height, \
	"so_long");
	render_map(&vars);
	mlx_key_hook(vars.win, handle_keypress, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

/*
//VERSION QUE ABRE VENTANA Y CARGA IMAGEN DE FONDO(con espacio negros sobrantes)
int main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
	{
		printf("Error: Unable to start MiniLibX\n");
		return (1);
	}
	vars.win = mlx_new_window(vars.mlx, 800, 600, "so_long");
	if (!vars.win)
	{
		printf("Error: The window could not be created\n");
		return (1);
	}
	vars.map = NULL;
	vars.map_width = 0;
	vars.map_height = 0;
	vars.player_x = 0;
	vars.player_y = 0;
	vars.moves = 0;
	vars.collectibles = 0;
	vars.exit_open = 0;
	vars.game_over = 0;
	vars.won = 0;

	vars.img_background = mlx_xpm_file_to_image(vars.mlx, "images/background.xpm", \
	&vars.map_width, &vars.map_height);
	vars.img_wall = mlx_xpm_file_to_image(vars.mlx, "images/wall.xpm", \
	&vars.map_width, &vars.map_height);
	vars.img_collectible = mlx_xpm_file_to_image(vars.mlx, "images/collectible.xpm", \
	&vars.map_width, &vars.map_height);
	vars.img_exit = mlx_xpm_file_to_image(vars.mlx, "images/exit.xpm", \
	&vars.map_width, &vars.map_height);
	vars.img_player = mlx_xpm_file_to_image(vars.mlx, "images/player.xpm", \
	&vars.map_width, &vars.map_height);

	if (!vars.img_background || !vars.img_wall || !vars.img_collectible || !vars.img_exit || !vars.img_player)
	{
		printf("Error: Unable to load images\n");
		return (1);
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img_background, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
*/
/*
int main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "diana");
	mlx_loop(win);
	return (0);
}
*/
