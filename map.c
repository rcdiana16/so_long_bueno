/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:48:10 by diana             #+#    #+#             */
/*   Updated: 2025/01/08 21:47:15 by diana            ###   ########.fr       */
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
	temp_map = "";
	line = get_next_line(fd);
	temp_map = ft_strjoin(temp_map, line);
	free(line);
	while ((line != NULL))
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp_map = ft_strjoin_free(temp_map, line);
		free(line);
	}
	close(fd);
	if (temp_map == NULL)
		return (NULL);
	map = ft_split(temp_map, '\n');
	free(line);
	free(temp_map);
	return (map);
}

int	validate_and_update_map(t_vars *vars, char **map, int x, int y)
{
	if (x < 0 || y < 0 || x > vars->map_width || y > vars->map_height)
		return (0);
	if (map[y][x] == 'E')
		vars->exit_found = 1;
	if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'E')
		return (0);
	if (map[y][x] == 'C')
		vars->game_c_count--;
	if (vars->exit_found == 1 && vars->game_c_count == 0)
		return (1);
	map[y][x] = 'V';
	return (-1);
}

int	explore_map(t_vars *vars, char **map, int x_start, int y_start)
{
	int	path_found;

	path_found = validate_and_update_map(vars, map, x_start, y_start);
	if (path_found != -1)
		return (path_found);
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
		free_map(new_map);
		clean_exit(vars);
	}
	free_map(new_map);
	return (0);
}
