/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:09:23 by diana             #+#    #+#             */
/*   Updated: 2024/12/23 19:42:43 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "structures.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

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
