/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:06:22 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/18 13:36:03 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		bytes_read;
	char	*buffer;
	int		i;

	i = 0;
	if (fd < 0 || BUFFERS_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFERS_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFERS_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return(NULL);
	}
	while (bytes_read > i && buffer[i] != '\n')
	{
		write(1, &buffer[i], 1);
		i++;
	}
	return (NULL);
}

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
}
