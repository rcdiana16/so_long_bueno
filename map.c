/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:48:10 by diana             #+#    #+#             */
/*   Updated: 2025/01/05 23:31:11 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *file)
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

int	explore_map(t_vars *vars, char **map, int x_start, int y_start)
{
	int	path_found;

	if (x_start < 0 || y_start < 0 || x_start > vars->map_width || \
	y_start > vars->map_height)
		return (0);
	if (map[y_start][x_start] == '1' || map[y_start][x_start] == 'V')
		return (0);
	if (map[y_start][x_start] == 'C')
		vars->game_c_count--;
	if (map[y_start][x_start] == 'E')
		vars->exit_found = 1;
	if (vars->exit_found == 1 && vars->game_c_count == 0)
		return (1);
	map[y_start][x_start] = 'V';
	path_found = 0;
	path_found = explore_map(vars, map, x_start + 1, y_start);
	if (!path_found)
		path_found = explore_map(vars, map, x_start - 1, y_start);
	if (!path_found)
		path_found = explore_map(vars, map, x_start, y_start + 1);
	if (!path_found)
		path_found = explore_map(vars, map, x_start, y_start - 1);
	return (path_found);
}

char	**duplicate_map(t_vars *vars)
{
	int		i;
	char	**new_map;

	new_map = malloc(sizeof(char *) * (vars->map_height + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < vars->map_height)
	{
		new_map[i] = ft_strdup(vars->map[i]);
		if (!new_map[i])
			return (NULL);
		i++;
	}
	new_map[vars->map_height] = NULL;
	return (new_map);
}

int	is_map_solvable(t_vars *vars)
{
	char	**new_map;

	new_map = duplicate_map(vars);
	if (explore_map(vars, new_map, vars->player_x, vars->player_y) != 1)
	{
		ft_printf("map no solvable\n");
		clean_exit(vars);
	}
	return (0);
}
