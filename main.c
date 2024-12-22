/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:12:52 by diana             #+#    #+#             */
/*   Updated: 2024/12/22 10:26:11 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"
#include "structures.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		printf("Error: Usage: ./so_long <map.ber>\n");
		return (1);
	}
	vars.mlx = mlx_init();
	
	vars.map = read_map(argv[1]);
	load_images(&vars);
	printf("%d\n", vars.img_width);
	vars.win = mlx_new_window(vars.mlx, 12 * vars.img_width, 5 * vars.img_heigth, "so_long");
	render_map(&vars);
	
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
