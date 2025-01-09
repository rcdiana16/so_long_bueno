/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diramire <diramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:22:55 by diramire          #+#    #+#             */
/*   Updated: 2025/01/09 11:35:54 by diramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_tmp_map(char *tmp_map, int fd)
{
	if (tmp_map == NULL)
	{
		free(tmp_map);
		close(fd);
		exit(1);
	}
	close(fd);
}

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
	check_tmp_map(temp_map, fd);
	map = ft_split(temp_map, '\n');
	free(line);
	free(temp_map);
	return (map);
}
