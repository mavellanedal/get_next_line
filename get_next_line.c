/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:06:22 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/23 20:25:16 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_first_left_char(int fd,	char *left_str)
{
	char	*buffer;
	int		rd_bytes,

	buffer = mallloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buffer);
			return(NULL);
		}
		buffer[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buffer);
	}
	free(buffer);
	return (left_str);
}

char	*get_next_line(int fd)
{
	const char	*left_str;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_str = read_first_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = get_new_line(left_str);
	left_str = get_new_left_str(left_str);
	return (line);
}
/*
int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY); // Abre el archivo "test.txt" en modo solo lectura
	if (fd == -1)
	{
		printf("ERROR");
		return (1);
	}

	get_next_line(fd); // Llama a tu función get_next_line, que debería escribir la línea

	close(fd); // Cierra el archivo
	return (0);
}*/
