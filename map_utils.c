/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:09:23 by diana             #+#    #+#             */
/*   Updated: 2025/01/02 18:27:38 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **read_map(char *file)
{
	int		fd;
	char	*line;
	char	**map;
	char	*temp_map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	temp_map = ft_strdup("");
	line = get_next_line(fd);
	temp_map = ft_strjoin(temp_map, line);
	while ((line != NULL))
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp_map = ft_strjoin(temp_map, line);
		free(line);
	}
	close(fd);
	map = ft_split(temp_map, '\n');
	free(temp_map);
	return (map);
}

void	render_tile_wall(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.wall, \
		x * vars->img_width, y * vars->img_heigth);
}

void	render_tile_background(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.background, \
		x * vars->img_width, y * vars->img_heigth);
}

void	render_tile_other(t_vars *vars, char tile, int x, int y)
{
	if (tile == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.collectible, \
		x * vars->img_width, y * vars->img_heigth);
	}
	else if (tile == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit, x \
		* vars->img_width, y * vars->img_heigth);
	}
	else if (tile == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.player, x \
		* vars->img_width, y * vars->img_heigth);
	}
}

void	render_tile(t_vars *vars, char tile, int x, int y)
{
	if (tile == '1')
		render_tile_wall(vars, x, y);
	else if (tile == '0')
		render_tile_background(vars, x, y);
	else
		render_tile_other(vars, tile, x, y);
}

void	render_row(t_vars *vars, int y)
{
	int x = 0;

	while (vars->map[y][x])
	{
		render_tile(vars, vars->map[y][x], x, y);
		x++;
	}
}

void	render_map(t_vars *vars)
{
	int y = 0;

	while (vars->map[y])
	{
		render_row(vars, y);
		y++;
	}
}

int	find_p_y_start(t_vars *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while(game->map[y])//recorre cada fila (alto) del mapa
	{
		x = 0;
		while (game->map[y][x])//recorre cada caracter de esa fila
		{
			if (game->map[y][x] == 'P')
			{
				game->player_y = y;
				game->player_x = x;
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*esta funcion me funciona para mostrar el mapa, pero con las nuevas
modificaciones tengo que dividirla, xk es muy grande
void	render_map(t_vars *vars)
{
	int x;
	int y;

	y = 0;
	
	while(vars->map[y])
	{
		x = 0;
		
		while (vars->map[y][x])//tengo que dejar tanto la [y] como la [x]
		{
			if (vars->map[y][x] == '1')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, \
			  vars->img.wall,  x * vars->img_width,  y * vars->img_heigth);
			}
			else if (vars->map[y][x] == '0')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, \
			  vars->img.background, x * vars->img_width, \
			  y * vars->img_heigth);
			}
				
			else if (vars->map[y][x] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, \
			  vars->img.collectible, x * vars->img_width, \
			  y * vars->img_heigth);
			}
			else if (vars->map[y][x] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, \
			  vars->img.exit, x * vars->img_width, y * vars->img_heigth);
			}
			else if (vars->map[y][x] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, \
			  vars->img.player, x * vars->img_width, y * vars->img_heigth);
			  
			}
			x++;
		}
		y++;
	}
}
*/

/*
static size_t	count_rows(char *file)
{
	int		fd;
	char	*line;
	size_t	rows;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	rows = 0;
	while (get_next_line(fd, &line))
	{
		free(line);
		rows++;
	}
	free(line);
	close(fd);
	return (rows);
}
*/ 