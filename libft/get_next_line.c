/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:07:04 by diana             #+#    #+#             */
/*   Updated: 2024/12/14 11:38:40 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strchr1(char *s1, int c)
{
	if (!s1)
		return (NULL);
	while (*s1)
	{
		if (*s1 == (char) c)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}

static ssize_t	read_into_buffer(int fd, char **buffer)
{
	char	tmp[BUFFER_SIZE + 1];
	char	*new_buffer;
	ssize_t	bytes_read;

	bytes_read = 1;
	if (!*buffer)
		*buffer = NULL;
	while (!ft_strchr1(*buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (-1);
		tmp[bytes_read] = '\0';
		new_buffer = ft_strjoin_free(*buffer, tmp);
		if (!new_buffer)
			return (-1);
		*buffer = new_buffer;
	}
	return (bytes_read);
}

static char	*get_line_in_buffer(char *buffer)
{
	int		i;
	char	*line;

	if (!buffer || !buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	else
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*trim_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	new_buffer = (char *)malloc(sizeof(char) * (ft_strlen1(buffer) - i + 1));
	if (!new_buffer)
		return (NULL);
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read_into_buffer(fd, &buffer);
	if (bytes_read < 0 || (!bytes_read && (!buffer || !buffer[0])))
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	line = get_line_in_buffer(buffer);
	buffer = trim_buffer(buffer);
	return (line);
}
