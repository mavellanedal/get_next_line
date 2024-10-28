/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:27:13 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/28 10:28:57 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_first_line(int fd, char *left_str)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(left_str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		left_str = ft_strjoin(left_str, buffer);
	}
	free (buffer);
	return (left_str);
}

char	*get_next_line(int fd)
{
	static char	*left_str[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str[fd] = get_first_line(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = get_new_line(left_str[fd]);
	left_str[fd] = new_left_str(left_str[fd]);
	return (line);
}
